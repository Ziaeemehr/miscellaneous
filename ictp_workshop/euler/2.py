#!/usr/bin/env python

a0 =0
a1 =1
sum1 = sum2 = 0

while sum1<4000000:
   sum1 = a0+a1
   a0 = a1
   a1 = sum1
   if sum1<4000000 and sum1%2==0:
      sum2 += sum1
print sum2
