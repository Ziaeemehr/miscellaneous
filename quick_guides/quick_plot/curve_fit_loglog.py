#!/usr/bin/env python

'''
in the name of Allah
''' 

import numpy as np 
import pylab as pl
import networkx as nx
import time 
from sys import exit 
import random

x = 
y =

pl.loglog(x,y,'ko')

from scipy.optimize import curve_fit
def myExpFunc(x, a, b):
    return a * np.power(x, b)

popt, pcov = curve_fit(myExpFunc, x, y)
pl.plot(x, myExpFunc(x, *popt), 'r-', 
        label="({0:.3f}*x**{1:.3f})".format(*popt))
pl.legend()
print "Exponential Fit: y = (a*(x**b))"
print "\ta = popt[0] = {0}\n\tb = popt[1] = {1}".format(*popt)

pl.show()