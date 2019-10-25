from igraph import *
import random
random.seed(1)


g = Graph.Erdos_Renyi(30, 0.3)
comms = g.community_multilevel()


plot(comms, mark_groups=True)
