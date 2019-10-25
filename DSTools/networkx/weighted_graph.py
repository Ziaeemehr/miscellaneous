import scipy as sp
import networkx as nx
import igraph as ig
import numpy as np


G = nx.complete_graph(5)

for e in nx.edges(G):
    G.add_edge(*e, weight=3)

A = nx.to_numpy_array(G,weight='weight')
B = nx.to_numpy_array(G,weight=None)

# print "A =\n", A
# print "B =\n", B
# print list(G.edges())
# print list(G.edges(data=True))[0][2]['weight']
# print list(G.edges(data=True))


# weights = (np.ones((5,5)) - np.eye(5))*0.5
# G.es['weight']=weights