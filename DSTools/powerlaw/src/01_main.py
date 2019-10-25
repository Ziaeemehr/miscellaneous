import numpy as np 
import pylab as pl 
from powerlaw import plot_pdf, Fit, pdf
from numpy import power
import collections

# http://mathworld.wolfram.com/RandomNumber.html
def generate_power_law_dist(N, e, xmin, xmax, seed=None):

    if seed != None:
        np.random.seed(seed)
    N = int(N)

    data = np.zeros(N, dtype=int)
    x1p = power(xmax, (e+1.0))
    x0p = power(xmin, (e+1.0))
    alpha = 1.0/(e+1.0)

    r = np.random.rand(N)

    for i in range(N):
        r = np.random.rand()
        # data[i] = int(np.round(power(((x1p - x0p)*r + x0p), alpha)))
        data[i] = power(((x1p - x0p)*r + x0p), alpha)

    #sum of degrees should be positive
    # from random import randint
    # if ((np.sum(data) % 2) != 0):
    #     i = randint(0, N)
    #     data[i] = data[i]+1

    print "sum :%g, mean :%g"%(np.sum(data), np.mean(data))
    return data
#--------------------------------------------------------------#
fig, ax = pl.subplots(1, figsize=(8, 10))

N = 5000
n = -2.6
xmin, xmax = 2.0, 10000.0
seed = 1234785

data = generate_power_law_dist(N, n, xmin, xmax, seed)

counter = collections.Counter(data)
pk = counter.values()
k = counter.keys()
pk = np.asarray(pk)/float(np.sum(pk))

fit = Fit(data)
fit.power_law.plot_pdf(ax=ax, linestyle=':', color='g')
# fit = Fit(data)
print fit.power_law.alpha
print fit.power_law.sigma

ax.loglog(k, pk, '.')
plot_pdf(data, color='r')

pl.show()

