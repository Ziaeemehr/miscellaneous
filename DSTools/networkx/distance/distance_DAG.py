import bct
import numpy as np
from copy import copy
import networkx as nx
import pylab as pl
from sys import exit


def imshow_plot(data, name="f"):
    from mpl_toolkits.axes_grid1 import make_axes_locatable
    fig1 = pl.figure(140, figsize=(6, 6))
    pl.clf()
    ax = pl.subplot(111)
    im = ax.imshow(data, interpolation='nearest',
                   cmap='afmhot')  # , cmap=pl.cm.ocean
    # ax.invert_yaxis()
    divider = make_axes_locatable(ax)
    cax = divider.append_axes("right", size="5%", pad=0.05)
    pl.colorbar(im, cax=cax)
    pl.savefig(name+".png")
    pl.close()
#-------------------------------------------------------------------#


def make_topological_sorted(A):
    DG = nx.from_numpy_matrix(A, create_using=nx.DiGraph())
    assert (nx.is_directed_acyclic_graph(DG)), "graph is not DAG"
    # new_node_label = nx.topological_sort(G, reverse=False)
    new_node_labels = list(reversed(list(nx.topological_sort(DG))))
    # new_node_label = list(list(nx.topological_sort(G, )))
    N = A.shape[0]
    An = np.zeros((N, N))
    for i in range(N):
        for j in range(N):
            An[i, j] = A[new_node_labels[i], new_node_labels[j]]
    DG = nx.from_numpy_matrix(An, create_using=nx.DiGraph())
    assert (nx.is_directed_acyclic_graph(DG)), "graph is not DAG"

    return An


N = 800
cname = str('SF-DAG-%d.dat' % N)
adj = np.loadtxt(cname, dtype=int)

if np.max(adj) == 2:
    adj = adj /2

def defineDirectedGraph(adj, fileName):
    # sum of rows are in-degrees
    in_degree = np.sum(adj, axis=1)
    # print("in degrees", in_degree)
    # sum of columns are out-degrees
    out_degree = np.sum(adj, axis=0)
    # print(out_degree)
    # finding the hub with zero in-degree
    print ("there is degree 0 in in degree: ", 0 in in_degree.tolist())
    hub_index = in_degree.tolist().index(0)
    print ("hub index : ", hub_index)

    # transpose adj to feed into directed graph in networkx
    DG = nx.from_numpy_matrix(adj.T, create_using=nx.DiGraph())
    print (nx.info(DG))
    imshow_plot(adj, fileName)
    print ('*' * 70)
    return hub_index, DG

# print ("before topological sorting" + "*" * 20)
# hub_index, DG = defineDirectedGraph(adj, "adj")

print ("after topological sorting" + "*" * 20)
sorted_adj = make_topological_sorted(adj)
np.savetxt(str("sorted-SF-DAG-%d.dat" % N), sorted_adj, fmt="%d")
hub_index, DG = defineDirectedGraph(sorted_adj, "sadj")
# print(DG.out_degree())
p = nx.shortest_path_length(DG, source=0)
distances = list(p.values())


def findIndices(distances, distance):

    distances = np.asarray(distances)
    return np.where(distances == distance)[0]

indices = findIndices(distances, 2)
print (indices)
print (np.asarray(distances)[indices])


# print (distances)
# pl.hist(distances, bins=range(np.max(distances)+1))

hist, bins = np.histogram(distances, bins="auto") # bins=20
width = (bins[1] - bins[0])
center = (bins[:-1] + bins[1:]) / 2
pl.bar(center, hist, align='center', width=width, color="k")
pl.xticks(range(np.max(distances) + 1))
pl.xlabel("distances", fontsize=14)
pl.ylabel("population", fontsize=14)
pl.tick_params(labelsize=14)
# print hist
# pl.show()
pl.savefig(str(N)+".png")

# pl.show()
# p = nx.shortest_path_length(DG, target=hub_index)
