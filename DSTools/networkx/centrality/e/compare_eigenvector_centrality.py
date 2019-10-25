import numpy as np
import networkx as nx
from sys import exit

G = nx.path_graph(4, create_using=nx.DiGraph())
# G= nx.reverse(G)
print nx.is_directed(G)
centrality = nx.eigenvector_centrality(G)
for node in centrality:
    print "%10d %15.9f " %(node, centrality[node])

print nx.is_directed(G)
centrality = nx.eigenvector_centrality_numpy(G)
for node in centrality:
    print "%10d %15.9f " % (node, centrality[node])
