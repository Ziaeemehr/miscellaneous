import bct
import numpy as np 
import pylab as pl 
import networkx as nx
from network import *

# ------------------------------------------------------------ #
def plot_hist(C, bins=None):
    fig, ax = pl.subplots(1)    
    if bins!=None :
        hist, bins = np.histogram(C,
                                  density=False,
                                  bins=bins)
    else:
        hist, bins = np.histogram(C,
                                  density=False)
    width = (bins[1] - bins[0])
    center = (bins[:-1] + bins[1:]) / 2
    ax.bar(center, hist, align='center', width=width)
# ------------------------------------------------------------ #

seed = 125
np.random.seed(seed)

HMN = True
# HMN = False

if HMN:
    gr = make_graph()
    Adj = gr.hierarchical_modular_graph(25, 3, 0.9, 0.25, 1,
            [2, 4.3, 5.7], seed=seed)
    Dij = gr.D
    N = gr.N
else:
    clusters = [20, 20, 20]
    N = np.sum(clusters)
    gr = make_graph()
    Adj = gr.modular_graph(N, 0.7, 0.1, clusters, 1, 2)
    Dij = gr.D


# Degree:
# dg = bct.degrees_und(Adj)
# plot_hist(dg, 20); pl.show()
# print bct.degrees_dir(A)

# Clustering coefficient:
# cl = bct.clustering_coef_bu(Adj)
# plot_hist(cl); pl.show()
# print np.mean(cl) #mean clustering

# Transitivity:
# tr = bct.transitivity_bu(Adj)
# print tr

#connected component:
# G = nx.erdos_renyi_graph(100, 0.03, seed=seed)
# Adj = np.asarray(nx.to_numpy_matrix(G))
# a = bct.get_components(Adj)
# print a[0], len(a[0]) #component number
# print a[1], len(a[1]) #vector of component sizes

# community detection:
# ml = bct.community_louvain(Adj, 1, B='modularity')  # gamma=1 for 4 cluster
# print ml[0] #communities
# print ml[1] #modularity
# print max(ml[0]) #n_community 
# print bct.transitivity_bu(Adj)
# print np.mean(bct.clustering_coef_bu(Adj))

mod = bct.modularity_und(Adj, gamma=1)
# print mod[0] 
# print mod[1]  # maximized modularity metric


#shortest path
# dist = bct.distance_bin(Adj)
# np.savetxt('distance.txt', dist, fmt='%d')
#characteristic path length
# ch = bct.charpath(dist)
# print  ch[0] # lambda
# print ch[1] #efficiency
# # print ch[2] #ecc
# print ch[3] #radius
# print ch[4] #diameter

# ecc = np.max(dist, axis=1)
# print np.min(ecc) #radius
# print np.max(ecc)  #diameter

#betweenness centrality:
# bc = bct.betweenness_bin(Adj)
# bcn = bc/((N-1.0)*(N-2.0)) #normalized bc
# plot_hist(bc); pl.show()

# Within-module degree z-score:
# zscore = bct.module_degree_zscore(Adj, mod[0])
# plot_hist(zscore); pl.show()

# pc = bct.participation_coef(Adj, mod[0])
# plot_hist(pc); pl.show()
