import networkx as nx
import community
import matplotlib.pyplot as plt 

G = nx.random_graphs.powerlaw_cluster_graph(300, 1, .4)

part = community.best_partition(G)
values = [part.get(node) for node in G.nodes()]

nx.draw_spring(G, cmap = plt.get_cmap('afmhot'), node_color = values, 
               node_size=30, with_labels=False)

mod = community.modularity(part,G)
print("modularity:", mod)

plt.show()
