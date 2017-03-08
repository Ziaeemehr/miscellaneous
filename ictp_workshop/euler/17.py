#!/usr/bin/env python
from sys import exit, argv



num_dict={1:'one',2:'two',3:'three',4:'four',5:'five',6:'six',
          7:'seven',8:'eight',9:'nine',11:'eleven',12:'twelve',
	  13:'thirteen',14:'fourteen',15:'fifteen',16:'sixteen',
	  17:'seventeen',18:'eighteen',19:'nineteen',
	  10:'ten',20:'twenty',30:'thirty',40:'forty',
	  50:'fifty',60:'sixty',70:'seventy',80:'eighty',90:'ninety',
	  100:'onehundred',1000:'onethousand'}


def f(num):
   if num in num_dict:
      return len(num_dict[num])
   elif num>100:
      hun = num/100
      rem = num%100
      #print hun,rem
      return len(num_dict[hun]+'hundred') + ((f(rem)+3) if rem  else 0)
   else:
      tens = num/10
      rem = num % 10
      return len(num_dict[tens*10])+(f(rem) if rem else 0)
   #elif num/1000:
   #   th = num/1000
   #   return len(num_dict[th]+'thousand')+f(num%1000)

letters = 0
print f(int(argv[1]))
for i in range(1,1001):
  #print i,f(i)
  letters += f(i)

print letters

