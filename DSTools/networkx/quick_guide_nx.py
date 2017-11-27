
# To remove self loops:
G = nx.Graph(G)
G.remove_edges_from(nx.selfloop_edges(G))

# Return a copy of the graph G with the nodes relabeled using consecutive integers.
convert_node_labels_to_integers(G, first_label=0, ordering='default', 
                                label_attribute=None)

>>>G = nx.path_graph(10)
>>>G1= nx.convert_node_labels_to_integers(G, 20)
>>>sorted(G)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>>sorted(G1)
[20, 21, 22, 23, 24, 25, 26, 27, 28, 29]



relabel_nodes(G, mapping, copy=True)
>>> G = nx.path_graph(3)
>>> sorted(G)
[0, 1, 2]
>>> mapping = {0: 'a', 1: 'b', 2: 'c'}
>>> H = nx.relabel_nodes(G, mapping)
>>> sorted(H)
['a', 'b', 'c']    

>>> G = nx.path_graph(3)
>>> H = nx.relabel_nodes(G, lambda x: x ** 2)
>>> list(H)
[0, 1, 4]                            

# all to all graph
>>> G = nx.complete_graph(9)
>>> G = nx.complete_graph(4, nx.DiGraph())
# A = nx.adjacency_matrix(G)
A = nx.to_numpy_matrix(G)
print type(A)
print A.shape


# attribute to edges:

G.add_edge(1, 2, weight=3)
G.add_edge(1, 3, weight=7, capacity=15, length=342.7)

attr_matrix(G, edge_attr=None, node_attr=None, 
            normalized=False, rc_order=None, 
            dtype=None, order=None)

G = nx.Graph()
G.add_edge(0,1,thickness=1,weight=3)
G.add_edge(0,2,thickness=2)
G.add_edge(1,2,thickness=3)
print nx.attr_matrix(G, rc_order=[0,1,2])
print nx.attr_matrix(G, edge_attr='thickness', rc_order=[0,1,2])
