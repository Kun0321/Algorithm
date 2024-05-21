#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include "boost_typedef.h"

void save_graph(
	Graph g, 
	const char name[], 
	property_map< Graph, 
	int EdgeProperties::* >::type weightmap, 
	std::vector<std::size_t> parent,
	std::vector<int> distance,
	const std::string file_path);

void show_graph(std::string file_path);

int main() {
	enum nodes{s, t, x, y, z, N};
	char name[] = {'s', 't', 'x', 'y', 'z'};

	typedef std::pair<int, int > E;

	E edge_array[] = { E(s, t), E(s, y), E(t, x), E(t, y),  E(t, z),  E(x, t),  E(y, x),  E(y, z),  E(z, s), E(z, x), };

	const int num_edges = sizeof(edge_array) / sizeof(E);
	int weight[num_edges] = {6, 7, 5, 8, -4,  -2, -3, 9, 2, 7 };

	Graph g(edge_array, edge_array + num_edges, N);
	property_map <Graph, int EdgeProperties::*>::type weight_map = get(&EdgeProperties::weight, g);

	int i = 0;
	for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei, ++i)
        weight_pmap[*ei] = weight[i];

    std::vector< int > distance(N, (std::numeric_limits< short >::max)());
    std::vector< std::size_t > parent(N);
    for (i = 0; i < N; ++i)
        parent[i] = i;
    distance[s] = 0;
    
    bool r = bellman_ford_shortest_paths(g, int(N),
        weight_map(weight_pmap)
        .distance_map(&distance[0])
        .predecessor_map(&parent[0]));

    if (r)
        for (i = 0; i < N; ++i)
            std::cout << name[i] << ": " << std::setw(3) << distance[i] << " "
            << name[parent[i]] << std::endl;
    else
        std::cout << "********** Negative Cycle **********" << std::endl;

    save_graph(g, name, weight_pmap, parent, distance, "bellman");

    show_graph("bellman-before");
    show_graph("bellman-after");

    return EXIT_SUCCESS;
}
