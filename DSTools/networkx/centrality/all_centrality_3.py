import numpy as np 
import networkx as nx
from sys import exit 


def centrality(cname, directed=False):

    C = np.genfromtxt('dat/'+cname+'.dat')

    if ((directed==True) & (np.max(C)==2)):
        C = C.T/2.0
    # print np.max(C)

    if directed == True:
        G   = nx.from_numpy_matrix(C, create_using=nx.DiGraph())
        BC  = np.asarray(nx.betweenness_centrality(G).values())
        IC  = np.asarray(nx.in_degree_centrality(G).values())
        OC  = np.asarray(nx.out_degree_centrality(G).values())
        EC  = np.asarray((nx.eigenvector_centrality_numpy(G)).values())
        KC  = np.asarray((nx.katz_centrality(G)).values())
        CC  = np.asarray((nx.closeness_centrality(G)).values())
        LC  = np.asarray((nx.load_centrality(G)).values())


        i_BC  = BC.argsort()[::-1]
        i_IC  = IC.argsort()[::-1]
        i_OC  = OC.argsort()[::-1]
        i_EC  = EC.argsort()[::-1]
        i_KC  = KC.argsort()[::-1]
        i_CC  = CC.argsort()[::-1]
        i_LC  = LC.argsort()[::-1]

        np.savetxt('dat/BC-' + cname +'.txt' , zip(i_BC, np.sort(BC)[::-1]) , fmt='%10d %15.9f')
        np.savetxt('dat/IC-' + cname +'.txt' , zip(i_IC, np.sort(IC)[::-1]) , fmt='%10d %15.9f')
        np.savetxt('dat/OC-' + cname +'.txt' , zip(i_OC, np.sort(OC)[::-1]) , fmt='%10d %15.9f')
        np.savetxt('dat/EC-' + cname +'.txt' , zip(i_EC, np.sort(EC)[::-1]) , fmt='%10d %15.9f')
        np.savetxt('dat/KC-' + cname +'.txt' , zip(i_KC, np.sort(KC)[::-1]) , fmt='%10d %15.9f')
        np.savetxt('dat/CC-' + cname +'.txt' , zip(i_CC, np.sort(CC)[::-1]) , fmt='%10d %15.9f')
        np.savetxt('dat/LC-' + cname +'.txt' , zip(i_LC, np.sort(LC)[::-1]) , fmt='%10d %15.9f')


    if directed == False:
        G = nx.from_numpy_matrix(C)
        BC = np.asarray(nx.betweenness_centrality(G).values())
        DC = np.asarray(nx.degree_centrality(G).values())
        LC = np.asarray((nx.load_centrality(G)).values())
        CC = np.asarray((nx.closeness_centrality(G)).values())
        EC = np.asarray((nx.eigenvector_centrality_numpy(G)).values())
     
        i_BC = BC.argsort()[::-1]
        i_DC = DC.argsort()[::-1]
        i_LC = LC.argsort()[::-1]
        i_CC = CC.argsort()[::-1]
        i_EC = EC.argsort()[::-1]

        np.savetxt('dat/BC-' + cname +'.txt', zip(i_BC, np.sort(BC)[::-1]), fmt='%10d %15.9f')
        np.savetxt('dat/DC-' + cname +'.txt', zip(i_DC, np.sort(DC)[::-1]), fmt='%10d %15.9f')
        np.savetxt('dat/LC-' + cname +'.txt', zip(i_LC, np.sort(LC)[::-1]), fmt='%10d %15.9f')
        np.savetxt('dat/CC-' + cname +'.txt', zip(i_CC, np.sort(CC)[::-1]), fmt='%10d %15.9f')
        np.savetxt('dat/EC-' + cname +'.txt', zip(i_EC, np.sort(EC)[::-1]), fmt='%10d %15.9f')

networks = {'SF-BDG':True, 'SF-DAG':True, 'SF-U':False,
            'SW-BDG':True, 'SW-DAG':True, 'SW-U':False,
 }
for i in networks.keys():
    try:
        centrality(i, networks[i])
        print i, networks[i], "passed"
    except:
        print i, networks[i], "failed"


