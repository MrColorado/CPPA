#include <boost/graph/graph_utility.hpp>
#include <iostream>

#include "graphadapter.hh"

enum { A, B, C, D, E, F, N };
const char* name = "ABCDEF";
//typedef boost::adjacency_matrix<boost::undirectedS, boost::property<boost::vertex_index_t, unsigned int>> Graph;
//typedef boost::adjacency_matrix<boost::undirectedS, Graphadapter<int>::VertexProperties> Graph;

int main() {

  //Graphadapter<int>::VertexProperties test[] = {{0, 10}, {1, 10}, {2, 20}};
  Graphadapter<unsigned>::VertexProperties test1(0, 10);
  Graphadapter<unsigned>::VertexProperties test2(1, 10);
  Graphadapter<unsigned>::VertexProperties test3(2, 20);


  Graphadapter<unsigned>::Graph g;

  add_vertex(test1, g);
  add_vertex(test2, g);
  add_vertex(test3, g);
  //add_edge(test1, test2, g);o
  //add_edge(test3, test2, g);

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
  /*
  std::cout << "edge set: ";
  boost::print_edges(g, name);
  std::cout << std::endl;

  std::cout << "out-edges: " << std::endl;
  boost::print_graph(g, name);
  std::cout << std::endl;
  */

  auto tmp = Graphadapter<unsigned>(&g);
  for (auto i : tmp.domain())
    std::cout << i << std::endl;

  std::cout << std::endl;

  for (auto i : tmp.values())
    std::cout << i << std::endl;
  return 0;
}