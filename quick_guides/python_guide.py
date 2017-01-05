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









