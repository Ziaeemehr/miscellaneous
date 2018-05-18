import igraph
import numpy as np

# get the row, col indices of the non-zero elements in your adjacency matrix
f = open('data1.txt','r')
a_numpy = np.genfromtxt(f)

conn_indices = np.where(a_numpy)

# get the weights corresponding to these indices
weights = a_numpy[conn_indices]

# a sequence of (i, j) tuples, each corresponding to an edge from i -> j
edges = zip(*conn_indices)

# initialize the graph from the edge sequence
G = igraph.Graph(edges=edges, directed=True)

# assign node names and weights to be attributes of the vertices and edges
# respectively
G.vs["name"] = ["1", "2", "3", "4"]
G.vs["label"] = G.vs["name"]
#G.vs['label'] = node_names

# I will also assign the weights to the 'width' attribute of the edges. this
# means that igraph.plot will set the line thicknesses according to the edge
# weights
G.es['width'] = weights

# plot the graph, just for fun
igraph.plot(G, layout="rt", labels=True, margin=80)