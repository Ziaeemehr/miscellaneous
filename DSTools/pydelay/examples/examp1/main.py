import numpy as np
import pylab as pl



def hermite_y(t, tn, Xn, Vn, tnp1, Xnp1, Vnp1):
    h = tnp1 - tn
    s = (t - tn) / h
    return (1.0 + 2 * s) * (s-1.0)**2 * Xn + \
        (3.0 - 2 * s) * (s)**2 * Xnp1 + h * s * \
        (s-1.0)**2 *Vn + h * (s - 1) * (s)**2 *Vnp1;

def dt_hermite_y(t, tn, Xn, Vn,tnp1, Xnp1, Vnp1): 
    h = tnp1 - tn
    s = (t - tn) / h
    return (1.0-4.0*s+3.0*(s)**2)*Vn + \
        s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h

def interp_y(t,n0):
    while(pt_t[n0+1]<t):
        n0++
    while(pt_t[n0]>t):
        n0--
    return hermit(t,pt_t[n0],pt_y[n0],pt_y_v[n0],
                    pt_t[n0+1],py_y[n0+1],pt_y_v[n0+1])
def dt_interp_y(t, n0) :
    while(pt_t[n0+1] < t):
        n0++
    while(pt_t[n0] > t): 
        n0--
    return dt_hermite(t, pt_t[n0], pt_y[n0], pt_y_v[n0], 
                         pt_t[n0+1],pt_y[n0+1],pt_y_v[n0+1])


dtmin = 0.0001;
dtmax = 0.1;
tfinal = 100.0;
RelTol = 1.0E-3;
AbsTol = 1.0E-6;
chunk = 10000;
nstart = 101;
dt0 = 0.01;
maxdelay = 1.; // Set the maximum delay here !!!
MaxIter = 10000000;
NumOfDiscont = 4;
discont[4] = {maxdelay, 2*maxdelay, 3*maxdelay, tfinal};
PARtau2 = 0.2;
PARtau1 = 1.0;



t = 0.0; 
int i;
NumberOfMinSteps = 0;
nextdsc = 0;
hitdsc = false;

TakingMinStep = 0;
SIM_n = nstart; 
SIM_size = SIM_n + chunk;
RelErr;
thresh = AbsTol/RelTol;
dt = dt0;
plag1 = SIM_n;
plag2 = SIM_n;

pt_y   = np.zeros((N,SIM_n+chunk))
pt_y_v = np.zeros((N,SIM_n+chunk))
pt_t   = np.zeros(SIM_n+chunk)

for i in range*(nstart+1): 
    pt_t[i]  = -maxdelay*(nstart-i)/nstart

for i in range(N):
    for j in range(nstart+1):
        pt_y[i,j]   = 1.
        pt_y_v[i,j] = 0.0

k1y1 = interp_y1(t - PARtau1, &plag2) ;
k1y3 =  pt_y2_ar[SIM_n] ;
k1y2 = interp_y1(t - PARtau1, &plag2) +interp_y2(t - PARtau2, &plag1) ;






