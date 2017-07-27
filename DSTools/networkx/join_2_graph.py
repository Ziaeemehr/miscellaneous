import networkx as nx
G=nx.Graph()
G.add_edge(1,2)
H=nx.Graph()
H.add_edge(1,3)
G = nx.compose(G,H)
print G.edges()
print G.nodes()
