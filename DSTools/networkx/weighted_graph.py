import scipy as sp
import networkx as nx
import igraph as ig
import numpy as np


G = nx.complete_graph(5)

for e in nx.edges(G):
    G.add_edge(*e, weight=3)

A = nx.to_numpy_matrix(G,weight='weight')
B = nx.to_numpy_matrix(G,weight=None)
A = np.asarray(A)
B = np.asarray(B)
print type(A), type(B)
print A
print B




# weights = (np.ones((5,5)) - np.eye(5))*0.5
# G.es['weight']=weights