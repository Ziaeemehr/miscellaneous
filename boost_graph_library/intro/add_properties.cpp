#include <iostream>  // for std::cout
#include <utility>   // for std::pair
#include <algorithm> // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------------------------

void example_0()
{
    using namespace boost;
    typedef adjacency_list<listS, vecS,
                           directedS,
                           no_property,
                           property<edge_weight_t, int>>
        Graph;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    typedef std::pair<int, int> Edge;

    const int num_nodes = 5;
    Edge edges[] = {Edge(0, 2),
                    Edge(1, 1), Edge(1, 3), Edge(1, 4),
                    Edge(2, 1), Edge(2, 3),
                    Edge(3, 4),
                    Edge(4, 0), Edge(4, 1)};
    int weights[] = {1, 2, 1, 2, 7, 3, 1, 1, 1};

    Graph G(edges, edges + sizeof(edges) / sizeof(Edge), weights, num_nodes);
}

int main(int argc, char *argv[])
{
    using namespace boost;

    typedef adjacency_list<vecS, vecS,
                           directedS,
                           no_property,
                           property<edge_weight_t, int>>
        MyGraph;

    // when instantiating without args, don't make the mistake of writing
    // MyGraph G();
    // you'll get cryptic/misleading errors if you do.
    MyGraph G;

    int v0 = add_vertex(G);
    int v1 = add_vertex(G);
    int v2 = add_vertex(G);

    // don't forget the .first, .second tells you if this is a new edge was added
    // (alternately, the edge already existed)
    auto e1 = add_edge(v0, v1, 10, G).first;
    auto e2 = add_edge(v1, v2, 20, G).first;

    return 0;
}