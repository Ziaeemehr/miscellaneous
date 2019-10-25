from graph_tool.all import *
from sys import exit
# import pylab as pl 

g = Graph()
ug = Graph(directed=False)
# print ug.is_directed()

ug = Graph()
ug.set_directed(False)
assert ug.is_directed() == False
g1 = Graph()
g2 = Graph(g1)
v1 = g.add_vertex()
v2 = g.add_vertex()
# print v1,v2
e = g.add_edge(v1, v2)
# print e
# graph_draw(g, vertex_text=g.vertex_index, vertex_font_size=18,
        #    output_size=(200, 200), output="two-nodes.png")
# print(v1.out_degree())
# print(e.source(), e.target())
vlist = g.add_vertex(10)
# print(len(list(vlist)))
# print vlist
# print type(vlist)

v = g.vertex(8)
g.add_edge(g.vertex(2), g.vertex(3))
e = g.edge(2, 3)

# e = g.add_edge(g.vertex(0), g.vertex(1))
# print(g.edge_index[e])

# for v in g.vertices():
#     print(v)

# for e in g.edges():
#     print(e)

'''
from itertools import izip
for v in g.vertices():
   for e in v.out_edges():
       print(e)
   for w in v.out_neighbors():
       print(w)

   # the edge and neighbors order always match
   for e, w in izip(v.out_edges(), v.out_neighbors()):
       assert e.target() == w
'''

# Fast iteration over vertices and edges
# print g.get_vertices()
# print(g.get_out_degrees(g.get_vertices()))
edges = g.get_edges()
print edges
print((edges[:, 0] * edges[:, 1]).sum())
