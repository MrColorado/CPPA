#include <iostream>
#include <boost/graph/graph_utility.hpp>
#include "graphadapter.hh"

enum { A, B, C, D, E, F, N };
const char* name = "ABCDEF";
typedef boost::adjacency_matrix<boost::undirectedS, boost::property<boost::vertex_index_t, unsigned int>> Graph;


int main() {
  std::cout << "Hello, World!" << std::endl;

  Graph g(N);
  add_edge(B, C, g);
  add_edge(B, F, g);
  add_edge(C, A, g);
  add_edge(C, C, g);
  add_edge(D, E, g);
  add_edge(E, D, g);
  add_edge(F, A, g);

  std::cout << "vertex set: ";
  boost::print_vertices(g, name);
  std::cout << std::endl;

  std::cout << "edge set: ";
  boost::print_edges(g, name);
  std::cout << std::endl;

  std::cout << "out-edges: " << std::endl;
  boost::print_graph(g, name);
  std::cout << std::endl;

  Graphadapter<unsigned int> tmp(g);

  for (unsigned int i : tmp.domain())
    std::cout << i << std::endl;

  return 0;
}