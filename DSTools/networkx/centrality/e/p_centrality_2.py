import numpy as np 
import networkx as nx
from sys import exit 

N = 100
ki = 10 
p = 0.1
C = np.genfromtxt('SF-U.dat', dtype=int)
G = nx.from_numpy_matrix(C)

degree = G.degree().values()
# print np.sort(degree)

cn =  np.asarray(nx.degree_centrality(G).values())
bc =  np.asarray(nx.betweenness_centrality(G).values())
icn = cn.argsort()[::-1]
ibc = bc.argsort()[::-1]

for i,j in zip(icn, ibc):
    print "%10.5f %10.5f %5d %5d"%(cn[i], bc[j], i,j)


