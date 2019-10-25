import networkx as nx
import numpy as np


G = nx.path_graph(3)
bb = nx.betweenness_centrality(G)
print bb
# print isinstance(bb, dict)

nx.set_node_attributes(G, bb, 'betweenness')

# for i in range(nx.number_of_nodes(G)):
# print G.node[i]#['betweenness']


# If you provide a list as the second argument, updates to the list will be reflected in the node attribute for each node:

G = nx.path_graph(3)
labels = []
nx.set_node_attributes(G, labels, 'labels')
labels.append('foo')
# for i in range(nx.number_of_nodes(G)):
#     print G.nodes[i]['labels']

# If you provide a dictionary of dictionaries as the second argument, the entire dictionary will be used to update node attributes:

G = nx.path_graph(3, create_using=nx.DiGraph())
attrs = {0: {'attr1': 20, 'attr2': 'nothing'}, 1: {'attr2': 3}}
nx.set_node_attributes(G, attrs)

# print "G.nodes[0]['attr1'] ", G.nodes[0]['attr1']
# print "G.nodes[0]['attr2'] ", G.nodes[0]['attr2']
# print "G.nodes[1]['attr2'] ", G.nodes[1]['attr2']
# print "G.nodes[2] ", G.nodes[2]
# print G.edges()
# for i in range(nx.number_of_nodes(G)):
#     print list(G.neighbors(i))
