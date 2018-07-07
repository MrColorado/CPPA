#pragma once

#include "boost/graph/adjacency_matrix.hpp"
#include "boost/graph/adjacency_list.hpp"

template <typename T>
class Graphadapter
{
public:

  struct VertexProperties
  {
    unsigned pos_;
    T value_;
    VertexProperties(unsigned pos, T value)
      : pos_(pos), value_(value)
    {}
  };

  //typedef boost::adjacency_matrix<boost::undirectedS, VertexProperties> Graph;
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, VertexProperties> Graph;
  using point_type = typename boost::graph_traits<Graph>::vertex_descriptor;
  using value_type = T;
  using pixel_type = std::pair<point_type, value_type>;
  using reference = T&;
  using const_reference = const T&;

  using vertex_iter = typename boost::graph_traits<Graph>::vertex_iterator;

  Graphadapter(Graph* graph);
  const_reference operator()(point_type p) const;
  reference operator()(point_type p);

  auto domain() const;

  auto values() const;
  auto values();

  auto pixels() const;
  auto pixels();

private:
  Graph* graph_;
};

#include "graphadapter.hxx"
