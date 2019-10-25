import graph_tool.all as gt
import numpy as np 
from sys import exit


adj = np.genfromtxt('C.dat')
g = gt.Graph(directed=False)
# g.add_edge_list(adj.nonzero())


g.add_vertex(len(adj))
edge_weights = g.new_edge_property('double')
num_vertices = adj.shape[0]
for i in range(num_vertices - 1):
    for j in range(i + 1, num_vertices):
        if adj[i, j] != 0:
            e = g.add_edge(i, j)
            edge_weights[e] = adj[i, j]


# pos = gt.arf_layout(g, max_iter=0)
pos = gt.radial_tree_layout(g, g.vertex(0))
gt.graph_draw(g, output="radial_tree_layout.pdf")



state = gt.minimize_nested_blockmodel_dl(g)
gt.draw_hierarchy(state, output="celegansneural_nested_mdl.pdf")
