#ifndef _BOOST_TYPEDEF_H // include guard
#define _BOOST_TYPEDEF_H

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/bellman_ford_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>

using namespace boost;

struct EdgeProperties
{
    int weight;
};

using Graph = adjacency_list< vecS, vecS, directedS, no_property, EdgeProperties >;

template < typename Graph, typename ParentMap > struct edge_writer
{
    edge_writer(const Graph& g, const ParentMap& p) : m_g(g), m_parent(p) {}

    template < typename Edge >
    void operator()(std::ostream& out, const Edge& e) const
    {
        out << "[label=\"" << get(edge_weight, m_g, e) << "\"";
        typename graph_traits< Graph >::vertex_descriptor u = source(e, m_g),
            v = target(e, m_g);
        if (m_parent[v] == u)
            out << ", color=\"black\"";
        else
            out << ", color=\"grey\"";
        out << "]";
    }
    const Graph& m_g;
    ParentMap m_parent;
};
template < typename Graph, typename Parent >
edge_writer< Graph, Parent > make_edge_writer(const Graph& g, const Parent& p)
{
    return edge_writer< Graph, Parent >(g, p);
}


#endif /* _BOOST_TYPEDEF_H */
