import numpy as np 
import networkx as nx
from sys import exit 

# G1 = nx.complete_graph(10)
# G2 = nx.path_graph(10)
G3 = nx.watts_strogatz_graph(100,10,0.1, seed=1235)
degree = G3.degree().values()

print np.sort(degree)

def print_max_diff(a):
    
    return np.max(a)-np.min(a)

def find_k_top_centrality(G, k):
    
    Cn = nx.degree_centrality(G)
    v  = np.asarray(Cn.values())
    indices = v.argsort()[-k::][::-1]
    return indices, v[indices]

a, b = find_k_top_centrality(G3, 30)

for i,j in zip(a,b):
    print i,j

for i in a:
    print i, G3.neighbors(i), ' *** ', print_max_diff(G3.neighbors(i)) 

    