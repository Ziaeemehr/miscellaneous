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

sp = nx.all_pairs_shortest_path(G)
# print sp
print sp['b']['g']
spl = nx.all_pairs_shortest_path_length(G)
print spl['b']['g']