import networkx as nx 
import community 
import numpy as np 
import pylab as pl 

Cij = np.loadtxt("HierarchicalModulr.dat")
print Cij.shape

A = np.matrix(Cij)
G = nx.from_numpy_matrix(A)

# G = nx.erdos_renyi_graph(100, 0.01)

# community.generate_dendrogram(graph, 
# part_init=None, weight='weight', 
# resolution=1.0)

dendrogram = community.generate_dendrogram(G,resolution=1)
p = len(dendrogram) - 1
print "dendrogram length", p

# for level in range(p) :
    # print("partition at level", level, "is", 
    # community.partition_at_level(dendrogram, level))  # NOQA

print "Modularity"
# community.modularity(partition, graph, weight='weight')
part = community.best_partition(G,resolution=0.5) #default resolution is 1
# print "keys",part.keys()
# print "values",part.values()
# print part
print community.modularity(part, G)

#drawing
# size = float(len(set(part.values())))
# print size
# pos = nx.spring_layout(G)
# count = 0
# for com in set(part.values()) :
#     count += 1.
#     list_nodes = [nodes for nodes in part.keys()
#                                 if part[nodes] == com]
#     nx.draw_networkx_nodes(G, pos, list_nodes, node_size = 20,
#                             node_color = str(count / size))
# nx.draw_networkx_edges(G,pos, alpha=0.5)
# pl.show()



