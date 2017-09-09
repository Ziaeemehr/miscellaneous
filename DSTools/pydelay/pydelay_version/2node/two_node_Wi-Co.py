"""
Wilson-Cowan equations for two node
"""
#from __future__ import division
from PyDSTool import *
from pydelay import dde23
from scipy.stats.stats import pearsonr 
from timeit import default_timer as timer
from my_modules import *
import sys
#import pdb
#---------------------------------------------------------#
t_final  = 2000           #final time of simulation
dt1 = 0.05                #dt between samples in time serie
tc = 500
itc = int(500./dt1)       #index of cut time


pardict = {
    'c1': 16.0,         # c1..4 strength of connections 
    'c2': 12,           # between subpopulations
    'c3': 15,
    'c4': 3,
    'aE': 1.3,
    'aI': 2.,
    'thetaE': 4.,
    'thetaI': 3.7,
    'rE': 1.0,          #refractory period of subpopulations E
    'rI': 1.0,          #refractory period of subpopulations I
    'kE': 0.9945,
    'kI': 0.9993,
    'tauE': 8.,         
    'tauI': 8.,
    'P1': 1.7,          # current to excitatory pop E1
    'P2': 1.7,
    'Q1': 0.,           # current to inhibitory pop I1
    'Q2': 0.,           
    'a1': 1.,           # E-E,a1..4 strength of connections between nodes
    'a2': 0.,           # I-E
    'a3': 0.,           # E-I
    'a4': 0.,           # I-I
    'eta': 1.0,         # coupling coefficient
    'dl': 0.5,          # delay between subpopulations in one node
    'DL': 0.5           # delay between nodes
    }
#---------------------------------------------------------#

delays = np.array([i*0.5 for i in range(1,45)]) 
ndelay = len(delays)
corEE = np.zeros(ndelay)
corII = np.zeros(ndelay)
columns = int((t_final-tc )/dt1)
print columns
E1 = np.zeros( (ndelay, columns) )
E2 = np.zeros( (ndelay, columns) )
freqE1 = np.zeros(ndelay)
n_t = 10  #length of t for history

print 'Computing ...'
start = timer()

#-main loop-----------------------------------------------#
for i in  range(ndelay):
    pardict['DL'] = delays[i]
    t_hist = np.linspace(0,pardict['DL'],n_t)
    E1_hist = np.random.uniform(0.0,1.,n_t) 
    E2_hist = np.random.uniform(0.0,1.,n_t) 
    I1_hist = np.random.uniform(0.0,1.,n_t) 
    I2_hist = np.random.uniform(0.0,1.,n_t) 
    histdic = {
        't': t_hist,
        'Exc1':  E1_hist,
        'Exc2':  E2_hist,
        'Inh1':  I1_hist,
        'Inh2':  I2_hist
        }
    eqns = {'Exc1': func(0,'E'),
            'Inh1': func(0,'I'),
            'Exc2': func(1,'E'),
            'Inh2': func(1,'I')}
    dde = dde23(eqns,pardict)
    dde.set_sim_params(dtmin= 1.e-3,AbsTol=9.e-5, 
                       RelTol=0.001 ,tfinal=t_final, dtmax=0.1, 
                       MaxIter = 1000000, dt0 = 0.001)
    dde.hist_from_arrays(histdic)
    dde.run()
    sol = dde.sample(tstart=tc,tfinal=None,dt=dt1)
    
    t  = sol['t']
    E1[i,:]  = sol['Exc1']
    E2[i,:]  = sol['Exc2']
    corEE[i] = find_corr(E1[i,:],E2[i,:])
    freqE1[i]  = find_frequency(t,dt1,E1[i,:])
    
end = timer()

print('code execution was : {} seconds'.format(end - start))
print 'ploting the time series and correlations'
    
#for i in range(ndelay):
#    plot_time_series(t,E1[i,:],E2[i,:])

plot_corr(delays,corEE)
plot_frequency(delays,freqE1)
plt.show()
