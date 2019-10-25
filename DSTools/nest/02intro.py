#!/usr/bin/env python

import nest
from sys import exit
import pylab as pl

neuron = nest.Create('iaf_psc_alpha')
nest.SetStatus(neuron, {'I_e': 376.0})

multimeter = nest.Create('multimeter')
nest.SetStatus(multimeter, 
                {'withtime': True, 
                 'record_from': ['V_m']})

spikedetector = nest.Create('spike_detector',
                    params={'withgid' : True, 
                            'withtime': True})

nest.Connect(multimeter, neuron)
nest.Connect(neuron, spikedetector)
nest.Simulate(1000.0)

dmm = nest.GetStatus(multimeter)[0]

Vms = dmm['events']['V_m']
ts = dmm['events']['times']

dSD = nest.GetStatus(spikedetector, keys='events')[0]
evs = dSD['senders']
ts = dSD['times']

neuron2 = nest.Create('iaf_psc_alpha')
nest.SetStatus(neuron2, {'I_e': 370.0})
nest.Connect(multimeter, neuron2)




exit(0)






# withgid indicates whether the spike detector is to 
# record the source id from which it received the event
# (i.e. the id of our neuron).                                   

# Connecting nodes with default connections
nest.Connect(multimeter, neuron)
nest.Connect(neuron, spikedetector)
nest.Simulate(1000.0) # in ms

# ------------------------------------------------------- #
# Connecting nodes with specific connections
# neuron receives 2 Poisson spike trains,
# one excitatory and the other inhibitory

noise_ex = nest.Create("poisson_generator")
noise_in = nest.Create("poisson_generator")
nest.SetStatus(noise_ex, {"rate": 80000.0})
nest.SetStatus(noise_in, {"rate": 15000.0})
# constant input current should be set to 0:
nest.SetStatus(neuron, {"I_e": 0.0})
# excitatory postsynaptic current of 1.2pA amplitude
syn_dict_ex = {"weight": 1.2} 
# inhibitory postsynaptic current of -2pA amplitude
syn_dict_in = {"weight": -2.0}
# print type(noise_ex), len(noise_ex)
# print noise_ex[0], noise_in[0]

noise = [noise_ex, noise_in]
nest.Connect(neuron, syn_spec=syn_dict_ex)
nest.Connect(neuron, syn_spec=syn_dict_in)

# plot the results
dmm = nest.GetStatus(multimeter)[0]
Vms1 = dmm["events"]["V_m"]
ts1 = dmm["events"]["times"]
pl.plot(ts1,Vms1)
pl.show()
exit(0)

