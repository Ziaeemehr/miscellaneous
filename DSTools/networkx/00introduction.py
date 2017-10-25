import networkx as nx


G=nx.Graph()
G.add_node(1)
G.add_nodes_from([2,3])
print G.nodes()

H = nx.path_graph(10)
G.add_nodes_from(H)
print G.nodes()
print G.edges()

G.add_edge(1,2)
e=(2,3)
G.add_edge(*e)
print G.edges()

G.add_edges_from([(1, 2), (1, 3)])
print G.edges()

G.add_edges_from(H.edges)
print G.edges()
print nx.info(G)

G.clear()
print G.nodes()
print G.edges()





