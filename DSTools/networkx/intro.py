# https://networkx.github.io/documentation/networkx-1.10/tutorial/tutorial.html
import networkx as nx 
import numpy as np 

#nodes
G = nx.Graph()
G.add_node(1)
G.add_nodes_from([2,3])

H = nx.path_graph(10)
G.add_nodes_from(H)
# G.add_node(H)

# print G.nodes()
# print G.edges()

#edges

G.add_edge(1,2)
e = (2, 3)
G.add_edge(*e)

#  (2,3,{'weight':3.1415}) or (2,3) 
G.add_edges_from([(1,2),(1,3)])
G.add_edges_from(H.edges())
# G.clear()
# print G.nodes()
# print G.edges()
# print list(G.neighbors(1))
# print G.number_of_nodes()
# print G.number_of_edges()

# Accessing edges
# print G[1]
# print G[1].keys()
# print G[1][2]
G.add_edge(1,3)
G[1][3]['color']='blue'
# print G[1][3]

#GRAPH ATTRIBUTES
FG = nx.Graph()
FG.add_weighted_edges_from([(1,2,0.125),(1,3,0.75),(2,4,1.2),(3,4,0.375)])

# for line in nx.generate_adjlist(G):
    # print(line)

# for (u,v,d) in FG.edges(data='weight'):
#     if d<0.5: 
#         print('(%d, %d, %.3f)'%(u,v,d))


G = nx.Graph(day='Friday')
# print G.graph

# NODE ATTRIBUTES
G.add_node(1, time='5pm', room=714)
# G.node[1]['room'] = 714
G.add_nodes_from([3,5], time='2pm')
# print G.node[1]
# print G.node[3]
# print G.node[5]
# print G.nodes(data=True)

#EDGE ATTRIBUTES
G = nx.Graph()
G.add_edge(1,2,weight=4.7)
G.add_edges_from([(3,4), (4,5)], color='red')
G.add_edges_from([(1,2,{'color':'blue'}),(2,3,{'weight':8})])
G[1][2]['weight']=4.7

# for e in G.edges():
#     i, j = e
#     print i, j, G[i][j]
# print "*******"
for n in G.nodes():
    print n,
    for nb in G.neighbors(n):
        print nb,
    print " "



