import numpy as np 
import networkx as nx
from sys import exit 
from math import sqrt
from numpy.linalg import eig



c = np.genfromtxt("dat/SF-DAG.dat")
c = (c.T)/2.0
GD = nx.from_numpy_matrix(c, create_using=nx.DiGraph())
G = nx.from_numpy_matrix(c)
centralityD = np.asarray(nx.betweenness_centrality(GD).values())
centrality  = np.asarray(nx.betweenness_centrality(G).values())
indD        = centralityD.argsort()[::-1]
ind         = centrality.argsort()[::-1]

for i,j in zip(indD, ind):
    print "%5d %15.9f %5d %15.9f" %\
    (i, centralityD[i], j, centrality[i])


# G = nx.path_graph(4)
# centrality = nx.betweenness_centrality(G)

# for node in centrality:
#     print "%10d %15.9f " %(node, centrality[node])

# G = nx.path_graph(4, create_using=nx.DiGraph())
# centrality = nx.betweenness_centrality(G)
# print 'DiGraph'
# for node in centrality:
#     print "%10d %15.9f " % (node, centrality[node])
