#!/usr/lib/python

import numpy as np

sum1=0
for i in range(1000) :
   if i%3==0 or i%5==0:
      sum1 += i
print sum1
