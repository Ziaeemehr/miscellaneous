#include <igraph.h>
#include <iostream>


using namespace std;

int main()
{

    igraph_t g;
    igraph_bool_t simple;
    int n = 1000;
    int m = 6;
    double power = 1.0;

//     igraph_rng_seed(igraph_rng_default(), 4);

    igraph_barabasi_game(
        /* graph=    */ &g,
        /* n=        */ n,
        /* power=    */ power,
        /* m=        */ m,
        /* outseq=   */ 0,
        /* outpref=  */ 0,
        /* A=        */ 1.0,
        /* directed= */ IGRAPH_UNDIRECTED,
        /* algo=     */ IGRAPH_BARABASI_PSUMTREE,
        /* start_from= */ 0);

    cout << "num of edges " << igraph_ecount(&g) << endl;
    cout << "num of vertices " << igraph_vcount(&g) << endl;
    cout << "graph is directed? " << igraph_is_directed(&g)<<endl;
    igraph_is_simple(&g, &simple);
    if (!simple) { 
        cout << "graph is not simple! \n";
        return 3; }

    //print to file
    igraph_adjlist_t adjlist;
    igraph_adjlist_init(&g, &adjlist, IGRAPH_ALL);

    std::string oname = "BA.txt";
    FILE *ofile;
    ofile = fopen(oname.c_str(), "w");
    igraph_write_graph_edgelist(&g, ofile);

    // max degree
    igraph_vector_t result;
    igraph_vector_init(&result, 0);
    igraph_degree(&g, &result, igraph_vss_all(), IGRAPH_ALL, 0);
    printf("Maximum degree is  %10i, vertex %2i.\n",
            (int)igraph_vector_max(&result), (int)igraph_vector_which_max(&result));
    
    // print the degree of each node
//     for (int i=0; i<n; i++)
//         cout << VECTOR(result)[i] << " ";
//     cout << endl;

    igraph_destroy(&g);
    igraph_vector_destroy(&result);

    return 0;
}
