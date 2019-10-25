import nest
from scipy.special import erf
from sklearn.svm import LinearSVC

#print nest.Models()
import pylab as pl 

neuron = nest.Create('iaf_psc_alpha')

print nest.GetStatus(neuron, 'I_e')
print nest.GetStatus(neuron, ['V_reset', 'V_th'])
nest.SetStatus(neuron, {'I_e':376.0})

multimeter = nest.Create('multimeter')
nest.SetStatus(multimeter, {'withtime':True, 'record_from':['V_m']})
spikedetector = nest.Create('spike_detector', 
                            params={'withgid':True, 'withtime':True})
nest.Connect(multimeter, neuron)
nest.Connect(neuron, spikedetector)
nest.Simulate(1000.0)

# print nest.GetStatus(multimeter)
dmm = nest.GetStatus(multimeter)[0]

Vms = dmm['events']['V_m']
ts = dmm['events']['times']

# pl.figure(1)
# pl.plot(ts, Vms, lw=2, marker='o', markersize=3)
# print nest.GetStatus(spikedetector, keys='events')
dSD = nest.GetStatus(spikedetector, keys='events')[0]
evs = dSD['senders']
ts = dSD['times']
pl.figure(2)
pl.plot(ts, evs, '.')

pl.show()
