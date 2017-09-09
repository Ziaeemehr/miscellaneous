import numpy as np
import pylab as pl

# import the solver
from pydelay import dde23

eqns = {'x':'-x+0.1'}
noise = {'x': 'D*gwn()'}
params = {'D':0.01}
dde = dde23(eqns = eqns,params=params,noise=noise)
histfunc = {'x':lambda t: 0.0}
dde.hist_from_funcs(histfunc,51)
dde.set_sim_params(tfinal = 20)
dde.run()
sol = dde.sample(0,20,0.1)
print dde.output_ccode()

x = sol['x']
t = sol['t']
pl.plot(t,x)
pl.show()
