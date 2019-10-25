#include <igraph.h>
#include <iostream>
#include <fstream>

// https://igraph.org/c/doc/igraph-Generators.html#igraph_erdos_renyi_game

using namespace std;

int main(void)
{
    int n=1000;
    int m = 5979; 
    igraph_integer_t diameter;
    igraph_t g;
    igraph_bool_t simple;
//     igraph_rng_seed(igraph_rng_default(), 4);
    igraph_erdos_renyi_game(&g, IGRAPH_ERDOS_RENYI_GNM, 
                            1000, 
                            m,
                            IGRAPH_UNDIRECTED, 
                            IGRAPH_NO_LOOPS);
    
    cout << "num of edges " << igraph_ecount(&g) << endl;
    cout << "num of vertices " << igraph_vcount(&g) << endl;
    cout << "graph is directed? " << igraph_is_directed(&g)<<endl;
    igraph_is_simple(&g, &simple);
    if (!simple) { 
        cout << "graph is not simple! \n";
        return 3; }
    igraph_adjlist_t adjlist;
    igraph_adjlist_init(&g, &adjlist, IGRAPH_ALL);
    
    // max degree
    igraph_vector_t result;
    igraph_vector_init(&result, 0);
    igraph_degree(&g, &result, igraph_vss_all(), IGRAPH_ALL, 0);
    printf("Maximum degree is  %10i, vertex %2i.\n",
            (int)igraph_vector_max(&result), (int)igraph_vector_which_max(&result));
    
    std::string oname = "ER.txt";
    FILE *ofile;
    ofile = fopen(oname.c_str(), "w");
    igraph_write_graph_edgelist(&g, ofile);

    igraph_destroy(&g);
    igraph_adjlist_destroy(&adjlist);
    igraph_vector_destroy(&result);
    
    return 0;
}