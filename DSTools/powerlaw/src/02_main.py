import numpy as np 
import pylab as pl 
from powerlaw import plot_pdf, Fit, pdf
from numpy import power
import powerlaw
import collections


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
        data[i] = int(np.round(power(((x1p - x0p)*r + x0p), alpha)))
        # data[i] = power(((x1p - x0p)*r + x0p), alpha)

    print "sum :%g, mean :%g"%(np.sum(data), np.mean(data))
    return data
#--------------------------------------------------------------#
fig, ax = pl.subplots(1, figsize=(8, 10))

N = 50000
n = -2.6
xmin, xmax = 2.0, 10000000.0
seed = 1234785

data = generate_power_law_dist(N, n, xmin, xmax, seed)


fit = powerlaw.Fit(data, discrete=True, xmin=7.0)

print fit.xmin, fit.xmax, fit.fixed_xmin, fit.fixed_xmax

ax = fit.plot_pdf(color='b', linewidth=2)
fit.power_law.plot_pdf(color='b', linestyle='--', ax=ax, label="pdf")
fit.plot_ccdf(color='r', linewidth=2, ax=ax)
fit.power_law.plot_ccdf(color='r', linestyle='--', ax=ax, 
label="ccdf")

ax.set_ylabel(u"p(X),  p(X>=x)")
ax.set_xlabel(r"data Frequency")
pl.legend()
print fit.power_law.alpha
print fit.power_law.sigma


# plot_pdf(data, color='r')
pl.savefig("../data/02.pdf")
# pl.show()

# x, y = fit.cdf()
# print x
# print y
# bin_edges, probability = fit.pdf()
# print bin_edges
# print probability
# print max(probability)
