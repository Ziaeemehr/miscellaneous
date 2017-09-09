import numpy as np
import pylab as pl
from pydelay import dde23


# We can define a c function to be used in the equations

eqns = { 'x' : 'f(x, x(t - tau))'}

mycode = """
double f(double x, double x_tau) {
    if (x > 1.0){
        return 0.25 * x_tau / (1.0 + pow(x_tau, 10.0)) -0.1*x;
    }
    else{
        return 0.45 * x;
    }
}
"""

dde = dde23(eqns=eqns, params={'tau': 15}, supportcode=mycode)

dde.set_sim_params(tfinal=1000, dtmax=1.0, AbsTol=10**-6, RelTol=10**-3)

histfunc = {'x': lambda t: 0.5 } 
dde.hist_from_funcs(histfunc, 51)
dde.run()

sol1 = dde.sample(1, 300, 1)
x1 = sol1['x']
pl.plot(x1)

#pl.plot(t, x)
#pl.xlim((0,40))
#pl.xlabel('$t$')
#pl.ylabel('$x$')
#pl.ylim((x.min(), x.max()))
pl.show()
