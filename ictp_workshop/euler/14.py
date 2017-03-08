#!/usr/bin/env python

#list1 =[]

def long_collatz(n):
   cntr = 0
   while (n>1):
      if n%2==0:
         n /=2
         #list1.append(n)
	 cntr +=1
      else:
         n = 3*n+1
         #list1.append(n)
	 cntr +=1
   return cntr

max_len = -10

for nu in range(1000000):
   list_len = long_collatz(nu)
   if list_len>max_len:
      max_len = list_len
      max_nu = nu


print max_len,max_nu



