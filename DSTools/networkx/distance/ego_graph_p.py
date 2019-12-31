import matplotlib.pyplot as plt
import networkx as nx
import pylab as pl
import random

G = nx.Graph()
nodes = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
edges = [('a', 'b'), ('a', 'c'), ('b', 'd'), ('b', 'e'),
         ('e', 'h'), ('c', 'f'), ('c', 'g')]
G.add_nodes_from(nodes)
G.add_edges_from(edges)


ego = nx.ego_graph(G, 'b', radius=2, center=False)
print(ego.nodes())


for i in range(1, len(nodes)):  # radius
    print ('radius ', i)
    for j in range(1):  # number of sampling
        seed = random.choice(nodes)
        ego = nx.ego_graph(G, seed, radius=i, center=False)
        print (len(ego.nodes()), seed)
        print (ego.nodes())
    print (" ")


# plot network
pos = nx.spring_layout(G)
nx.draw_networkx_nodes(G, pos,
                       #    nodelist=list(range(len(nodes))),
                       nodelist=nodes,
                       node_color='r',
                       node_size=500,
                       alpha=0.8)
nx.draw_networkx_edges(G, pos, width=2.0, alpha=0.5, edgelist=edges)
labels = {}
for i in range(len(nodes)):
    labels[nodes[i]] = nodes[i]
nx.draw_networkx_labels(G, pos, labels, font_size=16)

plt.axis("off")
plt.show()
