void make_barabasi_albert_graph(
    const int n,
    const int m,
    const double power,
    int &max_degree,
    dim2& adj_matrix)
{
    /*!
     * \brief make barabasi albert graph and return the adjacency matrix
     * \param n The number of vertices in the graph
     * \param m The number of outgoing edges generated for each vertex. 
     */
    igraph_t g;
    igraph_bool_t simple;
    igraph_rng_seed(igraph_rng_default(), 42);

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

    
    igraph_is_simple(&g, &simple);
    if (!simple)
    {
        cout << "graph is not simple! \n";
        exit(EXIT_FAILURE);
    }

    //get the adjacency list------------------------------------
    igraph_adjlist_t adjlist;
    igraph_adjlist_init(&g, &adjlist, IGRAPH_ALL);

    // write to file--------------------------------------------
    std::string oname = "dat/BA.txt";
    FILE *ofile;
    ofile = fopen(oname.c_str(), "w");
    igraph_write_graph_edgelist(&g, ofile);
    fclose(ofile);

    // max degree-----------------------------------------------
    igraph_vector_t result;
    igraph_vector_init(&result, 0);
    igraph_degree(&g, &result, igraph_vss_all(), IGRAPH_ALL, 0);
    
    max_degree = (int)igraph_vector_max(&result);
    
    // write to vector
    vector<vector<int>> adjlist_vec= read_adj_list("dat/BA.txt");
    adj_matrix = adj_list_to_matrix(adjlist_vec, n, 0);

    // cout << "num of edges " << igraph_ecount(&g) << endl;
    // cout << "num of vertices " << igraph_vcount(&g) << endl;
    // cout << "graph is directed? " << igraph_is_directed(&g) << endl;
    // printf("Maximum degree is  %10i, vertex %2i.\n",
    //        (int)igraph_vector_max(&result), (int)igraph_vector_which_max(&result));

    igraph_destroy(&g);
    igraph_vector_destroy(&result);
}
/*------------------------------------------------------------*/
void make_erdos_renyi_graph(
    const int n,
    const int m,
    int &max_degree,
    dim2 &adj_matrix)
{
    /*!
     * \brief make erdos renyi graph and return the adjacency matrix
     * \param n number of nodes
     * \param m number of links
     * \param max_degree maximum degree
     * \param adj_matrix adjacency matrix 
     */
    igraph_t g;
    igraph_bool_t simple;

    igraph_rng_seed(igraph_rng_default(), 42);

    igraph_erdos_renyi_game(&g, IGRAPH_ERDOS_RENYI_GNM,
                            n,
                            m,
                            IGRAPH_UNDIRECTED,
                            IGRAPH_NO_LOOPS);

    
    igraph_is_simple(&g, &simple);
    if (!simple)
    {
        cout << "graph is not simple! \n";
        exit(EXIT_FAILURE);
    }

    //get the adjacency list------------------------------------
    igraph_adjlist_t adjlist;
    igraph_adjlist_init(&g, &adjlist, IGRAPH_ALL);

    // write to file--------------------------------------------
    std::string oname = "dat/ER.txt";
    FILE *ofile;
    ofile = fopen(oname.c_str(), "w");
    igraph_write_graph_edgelist(&g, ofile);
    fclose(ofile);

    // max degree-----------------------------------------------
    igraph_vector_t result;
    igraph_vector_init(&result, 0);
    igraph_degree(&g, &result, igraph_vss_all(), IGRAPH_ALL, 0);
    
    max_degree = (int)igraph_vector_max(&result);

    // write to vector------------------------------------------
    vector<vector<int>> adjlist_vec = read_adj_list("dat/ER.txt");
    adj_matrix = adj_list_to_matrix(adjlist_vec, n, 0);

    
    // cout << "num of edges " << igraph_ecount(&g) << endl;
    // cout << "num of vertices " << igraph_vcount(&g) << endl;
    // cout << "graph is directed? " << igraph_is_directed(&g) << endl;
    //     cout << endl;
    // printf("Maximum degree is  %10i, vertex %2i.\n",
    //        (int)igraph_vector_max(&result), (int)igraph_vector_which_max(&result));

    igraph_destroy(&g);
    igraph_vector_destroy(&result);
}

// if (seed!=-1) {
//     srand(time(NULL));
//     int seed0 = rand() % 100000000+1;
//     cout << seed0 << "\n";
//     igraph_rng_seed(igraph_rng_default(), int(seed0));
// }
// print the degree of each node
//     for (int i=0; i<n; i++)
//         cout << VECTOR(result)[i] << " ";