import community
import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import pylab as pl 
from sys import exit


def multilevel(data):
    '''Community structure based on the multilevel algorithm of
       Blondel et al'''

    conn_indices = np.where(data)
    weights = data[conn_indices]
    edges = zip(*conn_indices)
    G = igraph.Graph(edges=edges, directed=False)
    G.es['weight'] = weights
    comm = G.community_multilevel(weights=weights, return_levels=False)
    return comm


Cij = np.loadtxt("HierarchicalModulr.dat")
print Cij.shape

A = np.matrix(Cij)
G = nx.from_numpy_matrix(A)


#first compute the best partition
partition = community.best_partition(G)

#drawing
size = float(len(set(partition.values())))
print size
pos = nx.spring_layout(G)
count = 0.
for com in set(partition.values()) :
    count = count + 1.
    list_nodes = [nodes for nodes in partition.keys()
                                if partition[nodes] == com]
    nx.draw_networkx_nodes(G, pos, list_nodes, node_size = 20,
                                node_color = str(count / size))


nx.draw_networkx_edges(G,pos, alpha=0.5)
plt.show()
