#!/usr/lib/env python3
import numpy as np
import pylab as pl
import networkx as nx

FF = np.array([[0, 0, 0],
               [1, 0, 0],
               [1, 1, 0]]).T
G = nx.from_numpy_array(FF, create_using=nx.DiGraph())
nodes = list(range(3))

nodes = list(G.nodes())
edges = list(G.edges())
# print ("in degree : ", G.in_degree)


pos = nx.spring_layout(G)
nx.draw_networkx_nodes(G, pos,
                       #    nodelist=list(range(len(nodes))),
                       nodelist=nodes,
                       node_color='r',
                       node_size=500,
                       alpha=0.8)
nx.draw_networkx_edges(G, pos, width=2.0, alpha=0.5, edgelist=edges)
labels = {}
for i in range(len(nodes)):
    labels[nodes[i]] = nodes[i]
nx.draw_networkx_labels(G, pos, labels, font_size=16)
pl.axis("off")
pl.savefig("FF.png")
pl.show()
