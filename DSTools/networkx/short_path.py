'''
Networkx: Get the distance between nodes : stackoverflow
'''

import numpy as np 
import networkx as nx 
from sys import exit 

G = nx.Graph()
G.add_nodes_from(['a','b','c','d','e','f','g','h'])
G.add_edges_from([('a','b'),('a','c'),('b','d'),('b','e'),
                  ('e','h'),('c','f'),('c','g')])

# sp = nx.all_pairs_shortest_path(G)
# for i in sp:
#     print(i)
path = dict(nx.all_pairs_shortest_path(G))
# print(path['a']['g'])



G = nx.path_graph(5)
# print(nx.shortest_path_length(G, source=0, target=4))
p = nx.shortest_path_length(G, source=0) # target not specified
p = nx.shortest_path_length(G, target=4)  # source not specified
p = dict(nx.shortest_path_length(G, weight=None))  # source,target not specified
# print(p)
ave = []
for i in p:
    ave_ = np.mean(list(p[i].values()))
    ave.append(ave_)
    
# print(np.mean(ave))
# print(nx.average_shortest_path_length(G, weight=None))

# https://networkx.github.io/documentation/stable/reference/algorithms/shortest_paths.html
average_shortest_path_length