import numpy as np
import pylab as pl
from math import exp,sin
from pydelay import dde23

eqns = {
    'y1':'y5(t-1)+y3(t-1)',
    'y2':'y1(t-1)+y2(t-0.5)',
    'y3':'y3(t-1)+y1(t-0.5)',
    'y4':'y5(t-1)*y4(t-1)',
    'y5':'y1(t-1)'
    }
tfinal = 2;
params = {}

dde = dde23(eqns=eqns, params=params)
dde.set_sim_params(tfinal=tfinal)
histfuncs = {
    'y1':lambda t: exp(t+1),
    'y2':lambda t: exp(t+0.5),
    'y3':lambda t: sin(t+1),
    'y4':lambda t: exp(t+1),
    'y5':lambda t: exp(t+1),
    }
dde.hist_from_funcs(histfuncs)
dde.run()
sol = dde.sample(0,tfinal,0.01)



pl.plot(sol['t'],sol['y1'],label='y1')
pl.plot(sol['t'],sol['y2'],label='y2')
pl.plot(sol['t'],sol['y3'],label='y3')
pl.plot(sol['t'],sol['y4'],label='y4')
pl.plot(sol['t'],sol['y5'],label='y5')
pl.legend(frameon=False)
pl.savefig('exer1.png')
pl.show()

#print dde.output_ccode()
