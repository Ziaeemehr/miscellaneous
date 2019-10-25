from igraph import *

g = Graph.Full(3)
g.vs["name"] = ["A", "B", "C"]
print g[1,2]
print g['A','B']
g['A','B'] = 0
print g.ecount()


#summary(g)
print g.is_weighted()

g["A", "B"] = 2
print g['A','B']
g.es['weight']=1.0
g["A", "B"] = 2
print g['A','B']

print g.es["weight"]


g = Graph.Full(3)
for e in g.es:
    print e.tuple

# (0, 1)
# (0, 2)
# (1, 2)
