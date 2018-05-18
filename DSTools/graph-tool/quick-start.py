from graph_tool.all import *

g = Graph()
ug = Graph(directed=False)
print ug.is_directed()

ug = Graph()
ug.set_directed(False)
assert ug.is_directed() == False
g1 = Graph()
g2 = Graph(g1)
v1 = g.add_vertex()
v2 = g.add_vertex()
print v1,v2
e = g.add_edge(v1, v2)
print e
graph_draw(g, vertex_text=g.vertex_index, vertex_font_size=18,
           output_size=(200, 200), output="two-nodes.png")
print(v1.out_degree())
# print(e.source(), e.target())
vlist = g.add_vertex(10)
print(len(list(vlist)))
print vlist, type(vlist)