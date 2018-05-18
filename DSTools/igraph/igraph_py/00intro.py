import igraph
print igraph.__version__
from igraph import *
from sys import exit

g = Graph()
g.add_vertices(3)
g.add_edges([(0,1),(1,2)])
g.add_edges([(0,2)])
g.add_vertices(3)
g.add_edges([(2,3),(3,4),(4,5),(5,3)])
print g.get_eid(5,3) #to get the edge ID

g.delete_edges(3)
print g
print '='*10
summary(g)

print '='*10
g1 = Graph.Tree(127, 2)
summary(g1)
#print g1.get_edgelist()
print g1.get_edgelist()[0:10]

print '='*10
#generates a geometric random graph
g1 = Graph.GRG(100, 0.2)
g2 = Graph.GRG(100, 0.2)
print g1.get_edgelist() == g2.get_edgelist()
print g1.isomorphic(g2)
#Two graphs which contain the same number of graph vertices connected in the same way are said to be isomorphic.
