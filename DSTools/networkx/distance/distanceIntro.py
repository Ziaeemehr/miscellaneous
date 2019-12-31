import bct
import numpy as np 
from copy import copy 
import networkx as nx 
import pylab as pl
from sys import exit


G = nx.path_graph(5, create_using=nx.DiGraph())
print(nx.is_directed(G))

pos = nx.layout.spring_layout(G)
M = G.number_of_edges()
nodes = nx.draw_networkx_nodes(G, pos, node_color='blue')
edges = nx.draw_networkx_edges(G, pos, arrowstyle='->',
                               arrowsize=10, edge_cmap=pl.cm.Blues, width=2)
# nx.draw(G)
pl.show()

# print(nx.shortest_path_length(G, source=0, target=4))
p = nx.shortest_path_length(G, source=0)
print(p.values())

