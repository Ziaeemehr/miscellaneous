import networkx as nx

G = nx.Graph()
nodes = ['a','b','c','d','e','f','g','h']
edges = [('a','b'),('a','c'),('b','d'),('b','e'),
         ('e','h'),('c','f'),('c','g')]
G.add_nodes_from(nodes)
G.add_edges_from(edges)

#print nx.to_numpy_matrix(G)

ego = nx.ego_graph(G, 'b', radius=2, center=False)
print(ego.nodes())


for i in range(1,len(nodes)):         #radius
    print 'radius ', i
    for j in range(1):                #number of sampling
        seed = random.choice(nodes)
        ego = nx.ego_graph(G, seed, radius=i, center=False)
        print len(ego.nodes()), seed
        print ego.nodes()
    print " "
