/*
    Graphviz document: https://graphviz.org/documentation/
*/
#include <fstream>
#include "boost_typedef.h"

//------------------------
// Save graph to .dot file
//
void save_graph(Graph g, 
    const char name [], 
    property_map< Graph, int EdgeProperties::* >::type weight_pmap,
    std::vector<std::size_t> parent,  // predecessor
    std::vector<int> distance,        // distance
    const std::string file_path)
{
    std::ofstream dot_file_1((file_path + "-before.dot").c_str());
    std::ofstream dot_file_2((file_path + "-after.dot").c_str());

    dot_file_1 << "digraph D {\n"
        << "  graph[dpi = 150]\n"
        << "  rankdir=LR\n"
        << "  size=\"5,3\"\n"
        << "  ratio=\"fill\"\n"
        << "  edge[style=\"bold\"]\n"
        << "  node[shape=\"circle\"]\n";

    dot_file_2 << "digraph D {\n"
        << "  graph[dpi = 150]\n"
        << "  rankdir=LR\n"
        << "  size=\"5,3\"\n"
        << "  ratio=\"fill\"\n"
        << "  edge[style=\"bold\"]\n"
        << "  node[shape=\"circle\"]\n";

    //---------------------------
    // Write vertex properties
    for (auto vd : make_iterator_range(vertices(g))) {
        if (name[vd] == 's')
            dot_file_1 << name[vd] << " "
            << "[label=\"" << "0" << "\""
            << ", xlabel=\"" << name[vd] << "\""
            << "];\n";
        else
            dot_file_1 << name[vd] << " "
            << "[label=\"" << "-" << "\""
            << ", xlabel=\"" << name[vd] << "\""
            << "];\n";

        dot_file_2 << name[vd] << " "
            << "[label=\"" << distance[vd] << "\""
            << ", xlabel=\"" << name[vd] << "\""
            << "];\n";
    } // end of for

    graph_traits< Graph >::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
    {
        graph_traits< Graph >::edge_descriptor e = *ei;
        graph_traits< Graph >::vertex_descriptor u = source(e, g),
            v = target(e, g);
        // VC++ doesn't like the 3-argument get function, so here
        // we workaround by using 2-nested get()'s.
        dot_file_1 << name[u] << " -> " << name[v] << "[label=\""
            << get(weight_pmap, e) << "\"";
        dot_file_2 << name[u] << " -> " << name[v] << "[label=\""
            << get(weight_pmap, e) << "\"";

        dot_file_1 << ", color=\"grey\"";

        if (parent[v] == u)
            dot_file_2 << ", color=\"black\"";
        else
            dot_file_2 << ", color=\"grey\"";
        dot_file_1 << "]\n";
        dot_file_2 << "]\n";
    }
    
    dot_file_1 << "}";
    dot_file_2 << "}";

    dot_file_1.close();
    dot_file_2.close();
} // end of save_graph
