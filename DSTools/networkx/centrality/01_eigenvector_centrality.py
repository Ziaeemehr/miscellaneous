import numpy as np 
import networkx as nx
from sys import exit 


c = np.genfromtxt("dat/SF-DAG.dat")
c = (c.T)/2.0
GD = nx.from_numpy_matrix(c, create_using=nx.DiGraph())
G = nx.from_numpy_matrix(c)
centralityD = np.asarray(nx.eigenvector_centrality_numpy(GD).values())
centrality  = np.asarray(nx.eigenvector_centrality_numpy(G).values())
indD        = centralityD.argsort()[::-1]
ind         = centrality.argsort()[::-1]

for i,j in zip(indD, ind):
    print "%5d %15.9f %5d %15.9f" %\
    (i, centralityD[i], j, centrality[i])

exit(0)
# G = nx.path_graph(4)
# centrality = nx.eigenvector_centrality(G)
# for node in centrality:
#     print "%10d %15.9f " %(node, centrality[node])

