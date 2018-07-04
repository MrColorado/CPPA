#pragma once

#include "boost/graph/adjacency_matrix.hpp"

template <class T>
class Graphadapter
{
  typedef boost::adjacency_matrix<boost::undirectedS, T> Graph;
  using point_type = typename boost::graph_traits<Graph>::vertex_descriptor;
  using value_type = T;
  using pixel_type = std::pair<point_type, value_type>;
  using reference = T&;
  using const_reference = const T&;

public:
  Graphadapter(Graph graph);
  const_reference operator()(point_type p) const;
  reference operator()(point_type p);

  auto domain() const;

  auto values() const;
  auto values();

  auto pixels() const;
  auto pixels();

private:
  Graph graph_;
};

#include "graphadapter.hxx"
