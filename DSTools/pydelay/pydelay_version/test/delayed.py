#!/usr/bin/python
"""
Wilson-Cowan equations for network of connectoms
"""
from timeit import default_timer as timer
from pydelay import dde23
from scipy.stats.stats import pearsonr 
from my_modules import *
import numpy as np
from math import sqrt
from copy import copy
from sys import exit

N = 9
v = 6000.

ifile1 = open('strength.txt','r')
Cij = np.genfromtxt(ifile1,dtype='float')
ifile1.close()
ifile2 = open('dij.txt','r')
dij = np.genfromtxt(ifile2,dtype='float')
ifile2.close()
max_delay = dij.max()


t_final  = 2000           #final time of simulation
dt1 = 0.05                #dt between samples in time serie
tc = 500
itc = int(500./dt1)       #index of cut time

#---------------------------------------------------------#
# history arrays 
n_t = 20  #length of t for history
t_hist = np.linspace(0,10,n_t)
E_keys = ['Exc'+str(i)  for i in range(N)]
E_values = np.random.uniform(0.0,1.,n_t) 
I_keys = ['Inh'+str(i)  for i in range(N)]
I_values = np.random.uniform(0.0,1.,n_t) 

# build history dictionaty from arrays
histdic = {'t':t_hist}
d1 = {}
for i in range(N):
    d1 = {E_keys[i]:E_values}    
    d2 = {I_keys[i]:I_values}
    histdic.update(d1)
    histdic.update(d2)


#build dictionaty of equations
d3 = dict(zip(E_keys,funcE(N,Cij,dij)))
d4 = dict(zip(I_keys,funcI(N)))
eqns = {}
eqns.update(d3)
eqns.update(d4)


print 'Computing ...'
start = timer()

dde = dde23(eqns)
dde.set_sim_params(dtmin= 1.e-3,AbsTol=9.e-5,
                   RelTol=0.001 ,tfinal=t_final, dtmax=0.1, 
                   MaxIter = 1000000, dt0 = 0.001)
dde.hist_from_arrays(histdic)
dde.run()
sol = dde.sample(tstart=tc,tfinal=None,dt=dt1)
t  = sol['t']
columns = int((t_final-tc )/dt1)
EE = np.zeros((N,columns))
for i in range(N):
    EE[i,:] = sol[E_keys[i]]

corr_matrix = find_correlation_matrix(EE,N)

end = timer()
print 'calculation done in %.4f seconds' % (end-start)

cor_file = open('correlations.txt','w')
for i in range(N):
    for j in range(N):
        cor_file.write('%.4f \t' % corr_matrix[i,j])
    cor_file.write('\n')

cor_file.close()

output = open('time.txt','w')
output.write('Calculation done in %.4f seconds' %(end-start))
output.close()
