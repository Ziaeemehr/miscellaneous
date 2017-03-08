#!/usr/bin/env python

600851475143

def prime_factors(n):
   factors = []
   d=2
   while n>1:
      while n%d ==0:
         factors.append(d)
	 n /= d
      d += 1
   return factors
a = prime_factors(600851475143) 
print "the largest factor is :" , max(a)
