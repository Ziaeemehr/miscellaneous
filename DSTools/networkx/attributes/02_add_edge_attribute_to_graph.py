import networkx as nx
import numpy as np


G = nx.erdos_renyi_graph(5, 0.5, seed=125)
edges = G.edges()

# print edges

bb = nx.edge_betweenness_centrality(G, normalized=False)
# print bb
nx.set_edge_attributes(G, bb, 'betweenness')

del G

G = nx.erdos_renyi_graph(5, 0.5, seed=125)
attrs = {}
for e in G.edges():
    attrs[e] = {'delay': 10, 'weight': 0.5}

print attrs
nx.set_edge_attributes(G, attrs)
n = nx.number_of_nodes(G)
print G[0][2]['delay']
A = np.zeros((n, n))
D = np.zeros((n, n))
for e in edges:
    A[e[0], e[1]] = A[e[1], e[0]] = G[e[0]][e[1]]['delay']
    D[e[0], e[1]] = D[e[1], e[0]] = G[e[0]][e[1]]['weight']

print A
print D