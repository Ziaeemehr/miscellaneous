import igraph
import numpy as np

#ifile = open('strength.txt','r')
#data = np.genfromtxt(ifile,dtype='float')
#print data[0:5,0:5]
#matrix = data.tolist()

f = open('data.txt','r')
data = np.genfromtxt(f)
data = data.tolist()
g = igraph.Graph.Adjacency(data)

igraph.summary(g)
print g.get_edgelist()
