import igraph
import numpy as np

matrix = [[0,1,2],[1,0,0],[2,0,0]]
g = igraph.Graph.Adjacency(matrix)
print g.get_edgelist()

igraph.summary(g)

print g.get_edgelist()[0]
