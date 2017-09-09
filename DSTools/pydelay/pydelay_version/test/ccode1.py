import numpy as np
from pydelay import dde23
import matplotlib.pyplot as plt

pardict = {
    'c1': 16.0,
    'c2': 12,  
    'c3': 15,
    'c4': 3,
    'a': 1.3,
    'theta': 4.,
    'r': 1.0,   
    'k': 0.9945,
    'tau': 8.,         
    'p': 1.7,  
    'dl': 10.  
    }


eqns = {
    'x': '-x(t-dl) + ( k-r * x(t-dl)) * f(c1*x(t-dl)+c2*y(t-dl)+p,a,theta)',
    'y': '-y(t-dl) + ( k-r * y(t-dl)) * f(c3*x(t-dl)-c4*y(t-dl),a,theta)'
    }

t_final = 2000
n_t = 10
t_hist = np.linspace(0,pardict['dl'],n_t)
x_hist = np.random.rand()*np.ones(n_t)
y_hist = np.random.rand()*np.ones(n_t)

histdic = {
        't': t_hist,
        'x':  x_hist,
        'y':  y_hist
        }

mycode = """
    double f(double S, double a, double theta) {
        return 1.0/(1.+exp(-a*(S-theta)))-1./(1+exp(a*theta)) ;
    }
    """

# initalise the solver
dde = dde23(eqns=eqns, params=pardict, supportcode=mycode)

dde.set_sim_params(dtmin= 1.e-3,AbsTol=9.e-5, 
                   RelTol=0.001 ,tfinal=t_final, dtmax=0.1, 
                   MaxIter = 1000000, dt0 = 0.001)
dde.hist_from_arrays(histdic)
dde.run()
sol = dde.sample(tstart=0,tfinal=t_final,dt=1./32)
    
t1  = sol['t']
x1  = sol['x']
y1  = sol['y']

plt.plot(t1,x1,t1,y1)
plt.show()






#par = {16.0,            # c1        0 
       #12.0,            # c2        1
       #15.0,            # c3        2
       #3.0,             # c4        3
       #1.7,             # IP        4
       #0.0,             # IQ        5
       #1.3,             # aE        6
       #2.0,             # aI        7
       #4.0,             # thetaE    8
       #3.7,             # thetaI    9
       #1.0,             # rE        10
       #1.0,             # rI        11
       #8.0,             # tauE      12
       #8.0,             # tauI      13
       #1.0              # eta       14
       #]
