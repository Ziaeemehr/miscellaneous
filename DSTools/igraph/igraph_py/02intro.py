from igraph import *

g = Graph([(0,1), (0,2), (2,3), (3,4), (4,2), (2,5), (5,0), (6,3), (5,6)])
#print g.vs
g.vs["name"] = ["Alice", "Bob", "Claire", "Dennis", "Esther", "Frank", "George"]
g.vs["age"] = [25, 31, 18, 47, 22, 23, 50]
g.vs["gender"] = ["f", "m", "f", "m", "f", "m", "m"]
g.es["is_formal"] = [False, False, True, True, True, False, True, False, False]
#print g.es[0].attributes()
g.es[0]['is_formal']=True
#print g.es[0]

print 'degree \t\t\t',g.degree()
print 'edge_betweenness \t',g.edge_betweenness()

#highest betweenness centrality
ebs = g.edge_betweenness()
max_eb = max(ebs)
print [g.es[idx].tuple for idx, eb in enumerate(ebs) if eb == max_eb]


print g.get_adjacency(type=2, attribute=None, default=0, eids=False)


g.vs["label"] = g.vs["name"]
color_dict = {"m": "blue", "f": "pink"}
layout = g.layout('kk')
plot(g, layout = layout, vertex_color = [color_dict[gender] for gender in g.vs["gender"]])
