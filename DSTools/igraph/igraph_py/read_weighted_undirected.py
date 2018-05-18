import igraph
import numpy as np


f = open('data2.txt','r')
data = np.genfromtxt(f)
conn_indices = np.where(data)
weights = data[conn_indices]
edges = zip(*conn_indices)
G = igraph.Graph(edges=edges, directed=False)
G.es['weight'] = weights
igraph.summary(G)
print G.get_edgelist()
igraph.plot(G, layout="rt", labels=False, margin=80)