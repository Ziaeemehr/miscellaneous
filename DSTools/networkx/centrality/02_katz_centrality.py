import numpy as np 
import networkx as nx
from sys import exit 
from math import sqrt
from numpy.linalg import eig


c = np.genfromtxt("dat/SF-DAG.dat")
c = (c.T)/2.0
G1 = nx.from_numpy_matrix(c, create_using=nx.DiGraph())
centrality1 = np.asarray(nx.katz_centrality(G1).values())
centrality2 = np.asarray(nx.katz_centrality_numpy(G1).values())
ind1        = centrality1.argsort()[::-1]
ind2        = centrality2.argsort()[::-1]


for i,j in zip(ind1, ind2):
    print "%5d %15.9f %5d %15.9f" %\
    (i, centrality1[i], j, centrality2[j])

exit(0)

# G = nx.path_graph(4)
# phi = (1+sqrt(5))/2.0  # largest eigenvalue of adj matrix
# centrality = nx.katz_centrality(G, 1/phi-0.01)

# for node in centrality:
#     print "%10d %15.9f " %(node, centrality[node])


# c = np.genfromtxt("dat/SF-DAG.dat").T/2.0
# G = nx.from_numpy_matrix(c, create_using=nx.DiGraph())
# w, v = eig(c)
# # print np.max(np.real(w))

# # kc = np.asarray(nx.katz_centrality(G, np.max().values()))
# kc = np.asarray(nx.katz_centrality(G).values())
# i_kc = kc.argsort()[::-1]

# for i in i_kc:
#     print "%5d %15.9f" % (i, kc[i])
