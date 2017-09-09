#!/usr/bin/python

plt.legend(frameon=False)

# debugging
import pdb
pdb.set_trace()

python -m pdb myscript.py

#Numpy array, how to select indices satisfying multiple conditions?
x = array([5, 2, 3, 1, 4, 5])
y = array(['f','o','o','b','a','r'])
out = y[(1 < x) & (x < 5)]


#Concatenate item in list to strings
sentence = ['this','is','a','sentence']
>>> '-'.join(sentence)
'this-is-a-sentence'

#Map two lists into a dictionary
keys = ['a', 'b', 'c']
values = [1, 2, 3]
dictionary = dict(zip(keys, values))
print dictionary
#{'a': 1, 'b': 2, 'c': 3}

 #concatenate two dictionaries to create a new one
 python -mtimeit -s'd1={1:2,3:4}; d2={5:6,7:9}; d3={10:8,13:22}' \
'd4 = dict(d1, **d2); d4.update(d3)'

1000000 loops, best of 3: 1.88 usec per loop


#Find all files in directory with extension .txt in Python
import glob, os
os.chdir("/mydir")
for file in glob.glob("*.txt"):
    print(file)

#or

import os
for file in os.listdir("/mydir"):
    if file.endswith(".txt"):
        print(file)
#or

import os
for root, dirs, files in os.walk("/mydir"):
    for file in files:
        if file.endswith(".txt"):
             print(os.path.join(root, file))
#or

import glob
glob.glob('./*.txt')


#fixed seed 
import  numpy as np
np.random.seed(123)
print np.random.rand(2)

#normal random distrbution
mu = 0; sigma = .1
np.random.normal(mu,sigma,1000)

a0 = np.array([1,2,3])
np.matlib.repmat(a0,2,3)
#size of figure
plt.figure(figsize=(10,10))

#trace and sum of matrix or 2D array
np.trace(A)
np.sum(A)
np.transpose(A)

#get the current time
>>> from time import gmtime, strftime
>>> strftime("%Y-%m-%d %H:%M:%S", gmtime())
'2009-01-05 22:14:39'

#imshow
fig = plt.figure()

ax1 = fig.add_subplot(2,1,1)
ax1.set_aspect('equal')
plt.imshow(Conn,interpolation='nearest', cmap='afmhot') # , cmap=plt.cm.ocean
plt.colorbar()
ax2 = fig.add_subplot(2,1,2)
ax2.set_aspect('equal')
plt.imshow(Corr,interpolation='nearest', cmap='afmhot') # , cmap=plt.cm.ocean
plt.colorbar()

#append
list.append(obj)


import matplotlib.gridspec as gridspec
fig = plt.figure(figsize=(10,6))
gs = gridspec.GridSpec(4, 1)
ax1 = plt.subplot(gs[0:3, 0])
plt.plot(t,sol[:,0])
plt.ylabel('V')
plt.tick_params(
    axis='x',          # changes apply to the x-axis
    which='both',      # both major and minor ticks are affected
    bottom='off',      # ticks along the bottom edge are off
    top='off',         # ticks along the top edge are off
    labelbottom='off') # labels along the bottom edge are off
ax2 = plt.subplot(gs[3, 0])
plt.plot(t,y)


#add row of time to the first row of matrix A
np.insert(A,0,t[:],axis=0) 



#extend and append:
x = [1, 2, 3]
x.append([4, 5])
#out: [1, 2, 3, [4, 5]]
x = [1, 2, 3]
x.extend([4, 5])
#out:[1, 2, 3, 4, 5]


#To delete the first row, do this:
x = numpy.delete(x, (0), axis=0)
#To delete the third column, do this:
x = numpy.delete(x,(2), axis=1)

#delete zero rows of ndarray
Conn[np.all(Conn == 0, axis=1)]
Conn = Conn[~np.all(Conn == 0, axis=1)]
#print with out new line
sys.stdout.write('%d '% item)


#numpy.ndarray.tolist
a = np.array([1, 2])
a.tolist()


#There's a simple way to check if matrix is symmetric using numpy:
(arr.transpose() == arr).all()

#How to count the occurrence of certain item in an ndarray in Python?
y = np.array([1, 2, 2, 2, 2, 0, 2, 3, 3, 3, 0, 0, 2, 2, 0])
np.count_nonzero(y == 1)

#How can I count the occurrences of a list item in Python?
[1, 2, 3, 4, 1, 4, 1].count(1)

from collections import Counter
>>z = ['blue', 'red', 'blue', 'yellow', 'blue', 'red']
>>Counter(z)
Counter({'blue': 3, 'red': 2, 'yellow': 1})

alist = ['a1', 'a2', 'a3']
for i, a in enumerate(alist):
    print i, a

0 a1
1 a2
2 a3

alist = ['a1', 'a2', 'a3']
blist = ['b1', 'b2', 'b3']

for a, b in zip(alist, blist):
    print a, b
a1 b1
a2 b2
a3 b3

alist = ['a1', 'a2', 'a3']
blist = ['b1', 'b2', 'b3']

for i, (a, b) in enumerate(zip(alist, blist)):
    print i, a, b

0 a1 b1
1 a2 b2
2 a3 b3




## run.py
import os 

os.system("make clean")
os.system("make")
for i , j in zip(g_n,tau_n):
    command = "./prog   "+ str(i) + " " + str(j)
    os.system(command)

#Using a string variable as a variable name
foo= 'bar'
exec(foo+" = 'somthing else'")
print bar
somthing else

foo= 'bar'
exec(foo+" = 1")
print bar

foo= 'bar'
exec(foo+" = np.random.rand()")

x='buffalo'    
exec("%s = %d" % (x,2))
