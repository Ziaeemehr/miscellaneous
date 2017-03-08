#!/usr/bin/env python
import sympy
from sys import argv
a1 = sympy.sympify(1)
a2 = sympy.sympify(2)

def f(n):
  if n==1:
     return a2
  while n != 1:
     return a1 + a1/(f(n-1)) 

print f(int(argv[1]))

