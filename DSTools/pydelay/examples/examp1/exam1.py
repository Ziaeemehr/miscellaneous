import numpy as np
import pylab as pl
from math import exp,sin
from pydelay import dde23

eqns = {'y1': 'y1(t-tau1)' ,
        'y2': 'y1(t-tau1)+y2(t-tau2)',
        'y3': 'y2'
        }

tfinal = 5.
params = {'tau1': 1.,
          'tau2': 0.2
          }
dde = dde23(eqns=eqns, params=params)
dde.set_sim_params(tfinal=tfinal)
histfuncs = {
    'y1':lambda t: 1.,
    'y2':lambda t: 1.,
    'y3':lambda t: 1.
    }

dde.hist_from_funcs(histfuncs)
dde.run()
sol = dde.sample(0,tfinal,0.01)

print dde.output_ccode()

pl.plot(sol['t'],sol['y1'],label='y1')
pl.plot(sol['t'],sol['y2'],label='y2')
pl.plot(sol['t'],sol['y3'],label='y3')
pl.legend(frameon=False)
pl.savefig('exam1.png')
pl.show()


