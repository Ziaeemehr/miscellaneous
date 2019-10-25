#include <igraph.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    igraph_t graph;
    igraph_rng_seed(igraph_rng_default(), 42);
    igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNP, 
                            1000, 
                            5.0/1000.0,
                            IGRAPH_UNDIRECTED, 
                            IGRAPH_NO_LOOPS);
    
    igraph_adjlist_t adjlist;
    igraph_adjlist_init(&graph, &adjlist, IGRAPH_ALL);
    
    std::string oname = "out.txt";
    FILE *ofile;
    ofile = fopen(oname.c_str(), "w");
    igraph_write_graph_edgelist(&graph, ofile);
    
    
    igraph_destroy(&graph);
    igraph_adjlist_destroy(&adjlist);
    return 0;
}