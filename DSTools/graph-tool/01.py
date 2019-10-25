from graph_tool.all import *
from sys import exit
from itertools import izip
from numpy.random import randint

'''
Property maps
'''

g = Graph()
g.add_vertex(100)
# insert some random links

for s,t in izip(randint(0,100, 100), randint(0, 100, 100)):
    g.add_edge(g.vertex(s), g.vertex(t))

vprop_double = g.new_vertex_property("double")            # Double-precision floating point
vprop_double[g.vertex(10)] = 3.1416

vprop_vint = g.new_vertex_property("vector<int>")         # Vector of ints
vprop_vint[g.vertex(40)] = [1, 3, 42, 54]

# Arbitrary python object.
eprop_dict = g.new_edge_property("object")                # In this case, a dict.
eprop_dict[g.edges().next()] = {"foo": "bar", "gnu": 42}

gprop_bool = g.new_graph_property("bool")                  # Boolean
gprop_bool[g] = True


from numpy.random import random

# this assigns random values to the vertex properties
vprop_double.get_array()[:] = random(g.num_vertices())

# or more conveniently (this is equivalent to the above)
vprop_double.a = random(g.num_vertices())
