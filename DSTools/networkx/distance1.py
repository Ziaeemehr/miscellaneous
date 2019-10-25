import bct
import numpy as np 
from copy import copy 
import networkx as nx 
import pylab as pl
from sys import exit


def adj_list_to_matrix(adj_list, N, directed=False):
    n_edges = adj_list.shape[0]
    C = np.zeros((N, N), dtype=int)
    if directed:
        weight = 2
    else:
        weight = 1
    for i in range(n_edges):
        a = adj_list[i, 0]
        b = adj_list[i, 1]
        C[a, b] = weight

    return C
#-------------------------------------------------------------------#


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


N = 200
cname = 'SF-DAG.dat'
adj = np.genfromtxt(cname, dtype=int)

in_degree = np.sum(adj, axis=1)
out_degree = np.sum(adj, axis=0)
print 0 in in_degree.tolist()
ind = in_degree.tolist().index(0)
print ind

G = nx.from_numpy_matrix(adj, create_using=nx.DiGraph())
print '***************************'
# print nx.is_directed(G)
# print G.number_of_edges()
# print G.number_of_nodes()
p = nx.shortest_path_length(G, target=ind)

dist_from_hub = np.asarray(p.values())

new_ind = np.argsort(dist_from_hub)
# print new_ind
# print dist_from_hub[new_ind]

# for i, j in zip(new_ind, dist_from_hub):
#     print '%g %g' % (i, j)

ordered_adj = np.zeros((N, N), dtype=int)

for i in range(N):
    for j in range(N):

        a = new_ind[i]
        b = new_ind[j]
        
        ordered_adj[i, j] = adj[new_ind[i], new_ind[j]]

np.savetxt('r'+cname, ordered_adj, fmt='%d')
imshow_plot(ordered_adj, 'ordered_adj')
imshow_plot(adj, 'adj')


# A = copy(dis)
# dis[dis>1e8] = 1000
# np.savetxt('dist.txt', dis, fmt='%7d')


# G = nx.from_numpy_matrix(adj, create_using=nx.DiGraph())
# print nx.shortest_path_length(G, source=2, target=4)
# pl.plot(range(N), in_degree, 'ro')
# pl.plot(range(N), out_degree, 'b^')
# pl.show()

