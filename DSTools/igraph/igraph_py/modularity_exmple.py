import numpy as np 
import pylab as pl 
import networkx as nx
from network import make_graph
from modules import  comm_unweighted 
import igraph 
from sys import exit 

clusters = [50,50]
gr = make_graph()
Adj = gr.modular_graph(sum(clusters), 
                        0.9, 0.1,
                        clusters, 
                        1, 1, 
                        plot_adj=False)
G = gr.G
print type(G)

comm = comm_unweighted(Adj)
print G.modularity(comm.membership)
# cl = igraph.Clustering(comm.membership)
# print cl.membership
# G = gr.G 
# print G.nodes()


# g = igraph.Graph.Full(3)+igraph.Graph.Full(3)
# weights = [1, 1, 1, 2, 2, 2]
# print g.modularity([0, 0, 0, 1, 1, 1])#, weights)

# cl = igraph.VertexClustering(G, G.nodes())
# cl.modularity


# igraph.modularity(G.nodes())
# print comm
# print type(G)
# modul = G.modularity(comm.membership)
