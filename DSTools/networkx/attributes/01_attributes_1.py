import networkx as nx
import numpy as np


# Access to edge attributes
G = nx.Graph()
G.add_weighted_edges_from(
    [(1, 2, 0.125),
        (1, 3, 0.75),
        (2, 4, 1.2),
        (3, 4, 0.375)])

# for e in G.edges():
#     i, j = e
#     print i, j, G[i][j]['weight']

# print G[1][2]['weight']


# Node attributes
G = nx.path_graph(3)
bb = nx.betweenness_centrality(G)
print bb
# print isinstance(bb, dict)

nx.set_node_attributes(G, bb, 'betweenness')

# for i in range(nx.number_of_nodes(G)):
# print G.node[i]#['betweenness']

aa = {0: 10, 1: 20, 2: 30}
nx.set_node_attributes(G, bb, 'attr2')

for i in range(nx.number_of_nodes(G)):
    print G.node[i]
