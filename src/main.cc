#include <iostream>
#include <boost/graph/graph_utility.hpp>
#include "graphadapter.hh"

enum { A, B, C, D, E, F, N };
const char* name = "ABCDEF";
//typedef boost::adjacency_matrix<boost::undirectedS, boost::property<boost::vertex_index_t, unsigned int>> Graph;
typedef boost::adjacency_matrix<boost::undirectedS, Graphadapter<int>::VertexProperties> Graph;

int main() {
  std::cout << "Hello, World!" << std::endl;

  Graphadapter<int>::VertexProperties test[] = {{0, 10}, {1, 10}, {2, 20}};
  Graphadapter<int>::VertexProperties test1 = {0, 10};
  Graphadapter<int>::VertexProperties test2 = {1, 10};
  Graphadapter<int>::VertexProperties test3 = {2, 20};


  Graph g;
  /*
  add_edge(B, C, g);
  add_edge(B, F, g);
  add_edge(C, A, g);
  add_edge(C, C, g);
  add_edge(D, E, g);
  add_edge(E, D, g);
  add_edge(F, A, g);
   */

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

  for (auto i : tmp.domain())
    std::cout << i << std::endl;

  std::cout << std::endl;

  for (auto i : tmp.values())
    std::cout << i << std::endl;

  //for (unsigned int i : tmp.values())
  //  continue; //std::cout << i << std::endl;

  return 0;
}