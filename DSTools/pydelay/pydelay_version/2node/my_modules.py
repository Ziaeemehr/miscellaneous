#!usr/bin/python
from PyDSTool import *
from pydelay import dde23
from scipy.stats.stats import pearsonr 
from timeit import default_timer as timer
import scipy.fftpack
import sys


def func(n,pop): 
    '''
    n is 0 or 1
    pop is 'I' or 'E'
    represent the E1,I1,E2 and I2
    '''
    En0 = ['Exc1(t-dl)','Exc2(t-dl)'] # 0 for inside population
    In0 = ['Inh1(t-dl)','Inh2(t-dl)']
    En1 = ['Exc1(t-DL)','Exc2(t-DL)'] # 1 for between populations 
    In1 = ['Inh1(t-DL)','Inh2(t-DL)']
    
    E_str = ['','']; coffE = ['',''];sE=['',''];Se=['','']; Ip = ['P1','P2']
    I_str = ['','']; coffI = ['',''];sI=['',''];Si=['','']; Iq = ['Q1','Q2']
    for k in range(0,2):
        coffE[k] = '1./tauE * (-'+En0[k]+'+ (kE - rE * '+En0[k]+')'
        coffI[k] = '1./tauI * (-'+In0[k]+'+ (kI - rI * '+In0[k]+')'

    for k in range(0,2):
        for l in range(0,2):
            if (k==l):
                continue
            else:
                sE[k] = 'c1*'+En0[k]+'-c2*'+In0[k]+'+'+Ip[k]+'+eta*(a1*'+En1[l]+'-a2*'+In1[l]+')'
                sI[k] = 'c3*'+En0[k]+'-c4*'+In0[k]+'+'+Iq[k]+'+eta*(a3*'+En1[l]+'-a4*'+In1[l]+')'
    for k in range(0,2):
        for l in range(0,2):
            if (k==l):
                continue
            else:
                Se[k] = '(1./(1+ exp(-aE*('+sE[k]+'-thetaE)))-1./(1.+exp(aE*thetaE)))'
                Si[k] = '(1./(1+ exp(-aI*('+sI[k]+'-thetaI)))-1./(1.+exp(aI*thetaI)))'
    for k in range(0,2):
        E_str[k] = coffE[k]+'*'+Se[k]+')'
        I_str[k] = coffI[k]+'*'+Si[k]+')'
    if (pop =='E'):
        return E_str[n]
    else:
        return I_str[n]
#---------------------------------------------------------#    
def find_frequency(t,dt,y):
    '''
    # N Number of samplepoints
    # dt sample spacing
    '''
    N = len(t)
    dt = dt * 1.e-3
    xf = np.linspace(0.0, 1.0/(2.0*dt), N/2)
    yf = scipy.fftpack.fft(y)
    y2f = 2.0/N * np.abs(yf[:N//2])
    plt.plot(xf, y2f)
    plt.xlim([0,100])
    # select a proper interval
    yout = y2f[ (10<xf) & (xf<100) ]
    xout =  xf[ (10<xf) & (xf<100) ]

    for index, item in enumerate(yout):
           if (item == max(yout)):
              ind,it = index, item
    return xout[ind]
#---------------------------------------------------------#
def plot_frequency(delays,freqE1,fignum=3):
    plt.figure(fignum)
    plt.plot(delays,freqE1,'k-',delays,freqE1,'ko') 
    plt.title('Frequency vs Delay')
    plt.xlabel('$Delay(ms)$')
    plt.ylabel('$f(Hz)$')
    plt.ylim([0,50])
    plt.savefig('./results/freq.png')
#---------------------------------------------------------#
def find_corr(x,y):
    temp1 = pearsonr(x,y)
    corr = temp1[0]
    return corr
#---------------------------------------------------------#
def plot_time_series(t,E1,E2,fignum = 1):
    plt.figure(fignum)
    plt.clf()
    plt.plot(t,E1,label='E1')
    #plt.plot(t,I1,label='I1')
    plt.plot(t,E2,label='E2')
    #plt.plot(t,I2,label='I2')
    plt.legend(frameon=False)
    plt.xlabel('time(ms)')
    plt.pause(0.01)
    plt.draw()
#---------------------------------------------------------#    
def plot_corr(delays,corEE,fignum=2):
    plt.figure(fignum)
    plt.plot(delays,corEE,'r-',label='E correlations')
    plt.plot(delays,corEE,'ro')
    #plt.plot(delays,corII,'b-',label='I correlations')
    #plt.plot(delays,corII,'bo')
    plt.legend(frameon=False)
    plt.xlabel('$Delay(ms)$')    
    plt.savefig('./results/corr.png')
    