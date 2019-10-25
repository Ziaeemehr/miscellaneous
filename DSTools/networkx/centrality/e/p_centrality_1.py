import numpy as np 
import networkx as nx
from sys import exit 

N = 100
ki = 10 
p = 0.1
C = np.genfromtxt('SF-DAG.dat', dtype=int)
G = nx.from_numpy_matrix(C, create_using=nx.DiGraph())

degree = G.degree().values()
# print np.sort(degree)

cn =  np.asarray(nx.degree_centrality(G).values())
bc =  np.asarray(nx.betweenness_centrality(G).values())
ind = np.asarray(nx.in_degree_centrality(G).values())
icn = cn.argsort()[::-1]
ibc = bc.argsort()[::-1]
iind= ind.argsort()[::-1]

for i,j,k in zip(icn, ibc, iind):
    print "%10.5f %10.5f %10.5f %5d %5d %5d"%(cn[i], bc[j], ind[k], i,j,k)


# def find_k_top_centrality(G, k):
    
#     Cn = nx.degree_centrality(G)
#     v  = np.asarray(Cn.values())
#     indices = v.argsort()[-k::][::-1]
#     return indices, v[indices]

# a, b = find_k_top_centrality(G3, 30)

# for i,j in zip(a,b):
#     print i,j

# for i in a:
#     print i, G3.neighbors(i), ' *** ', print_max_diff(G3.neighbors(i))     
# print nx.is_directed(G)
# A = nx.to_numpy_matrix(G)
# np.savetxt('A.dat', A, fmt='%d')
# G1 = nx.complete_graph(10)
# G2 = nx.path_graph(10)
# G3 = nx.watts_strogatz_graph(N, ki, p, seed=1235)
