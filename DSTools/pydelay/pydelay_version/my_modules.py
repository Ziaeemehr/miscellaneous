#!usr/bin/python
#from PyDSTool import *
import numpy as np
from pydelay import dde23
from scipy.stats.stats import pearsonr 
from timeit import default_timer as timer
import scipy.fftpack
from sys import exit
from copy import copy

c1 = 16.0         # c1..4 strength of connections 
c2 = 12           # between subpopulations
c3 = 15
c4 = 3
aE = 1.3
aI = 2.
thetaE = 4.
thetaI = 3.7
rE = 1.0         #refractory period of subpopulations E
rI = 1.0         #refractory period of subpopulations I
kE = 0.9945,
kI = 0.9993,
tauE = 8.
tauI = 8.
P =1.7           # current to excitatory pop E1
Q = 0.           # current to inhibitory pop I1
eta = 1.0        # coupling coefficient
#'dl': 0.,       # delay between subpopulations in one node
#'DL': 0.5       # delay between nodes


#---------------------------------------------------------#
def funcE(n,C,D): 
    '''
    n is 0 .. N number of nodes in connectome
    '''
    En = ['Exc'+str(i)  for i in range(n)]
    In = ['Inh'+str(i)  for i in range(n)]
    E_str = ['' for i in range(n)]
    coffE = ['' for i in range(n)]
    sE = ['' for i in range(n)]
    Se = ['' for i in range(n)]
    Ip = ['P' for i in range(n)]
    #Ip = ['P'+str(i) for i in range(n)]
    
    for k in range(n):
        coffE[k] = str(1./tauE)+'*(-'+En[k]+'+('+str(kE-rE)+'*'+En[k]+')'
        print coffE    
        exit(0)

        
    for k in range(n):
        temp2 = []
        temp1 = []
        for l in range(n):
            if (k==l):
                continue
            else:
                temp1.append( str(C[k,l])+'*'+En[l]+'(t-'+str(D[k,l])+')')
        temp2 = '+'.join(temp1)
        sE[k] = str(c1)+'*'+En[k]+'-'+str(c2)+'*'+In[k]+'+'+Ip[k]+'+'+str(eta)+'/'+str(float(n))+'*('+temp2+')'

    for k in range(n):
        Se[k] = '(1./(1+ exp(-'+str(aE)+'*('+sE[k]+'-'+str(thetaE)+')))-'+str(1./(1.+exp(aE*thetaE)))
        E_str[k] = coffE[k]+'*'+Se[k]+')'

    return E_str

#---------------------------------------------------------#
def funcI(n): 
    '''
    n is 0 .. N number of nodes in connectome
    '''
    En = ['Exc'+str(i)  for i in range(n)]
    In = ['Inh'+str(i)  for i in range(n)]
    I_str = ['' for i in range(n)]
    coffI = ['' for i in range(n)]
    sI = ['' for i in range(n)]
    Si = ['' for i in range(n)]
    Iq = ['Q' for i in range(n)]
    #Iq = ['Q'+str(i) for i in range(n)]

    for k in range(n):
        coffI[k] = str(1./tauI)+'*(-'+In[k]+'+('+str(kI-rI)+'*'+In[k]+')'

    for k in range(n):
        sI[k] = str(c3)+'*'+En[k]+'-'+str(c4)+'*'+In[k]+'+'+Iq[k]
        
    for k in range(n):
        Si[k] = '(1./(1+ exp(-'+str(aI)+'*('+sI[k]+'-'+str(thetaI)+')))-'+str(1./(1.+exp(aI*thetaI)))
        I_str[k] = coffI[k]+'*'+Si[k]+')'

    return I_str
#---------------------------------------------------------#

def find_correlation_matrix(x,n):
    corr = np.identity((n))
    for i in range(n-1):
        for j in range(i+1,n):
            temp = pearsonr(x[i,:],x[j,:])
            corr[i,j] = temp[0]
	    corr[j,i] = temp[0]
    return corr
#---------------------------------------------------------#




















#n_t = 10  #length of t for history
#t_hist = np.linspace(0,max_delay,n_t)
#E_keys = ['Exc'+str(i)  for i in range(N)]
#E_values = np.random.uniform(0.0,1.,n_t) 
#I_keys = ['Inh'+str(i)  for i in range(N)]
#I_values = np.random.uniform(0.0,1.,n_t) 

#def build_array_hist(E_keys,E_values,
                    #I_keys,I_values,
                    #t_hist):
    
    #histdic = {'t':t_hist}
    #d1 = {}
    #for i in range(N):
        #d1 = {E_keys[i]:E_values}    
        #d2 = {I_keys[i]:I_values}
        #histdic.update(d1)
        #histdic.update(d2)
    #return histdic
#def build_eqns_dict(E_keys,I_keys):
    #d3 = dict(zip(E_keys,funcE(N,C,D)))
    #d4 = dict(zip(I_keys,funcI(N)))
    #eqns = {}
    #eqns.update(d3)
    #eqns.update(d4)
