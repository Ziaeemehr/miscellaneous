import networkx as nx 
import numpy as np 
import pylab as pl 

G = nx.path_graph(4)
G.add_edge(5, 6)
graphs = list(nx.connected_component_subgraphs(G))

print [graphs[i].number_of_nodes() for i in range(len(graphs))]
print [graphs[i].number_of_edges() for i in range(len(graphs))]


nx.draw_circular(G, with_labels=True)
pl.show()
