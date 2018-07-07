#include <range/v3/view/iota.hpp>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/counted.hpp>

#include <vector>
#include <iostream>

template <class T>
Graphadapter<T>::Graphadapter(Graph graph)
  : graph_(graph)
{
}

template <class T>
const T& Graphadapter<T>::operator()(point_type p) const
{
  return graph_[p];
}

template <class T>
T& Graphadapter<T>::operator()(point_type p)
{
  return graph_[p];
}

template <class T>
auto Graphadapter<T>::domain() const
{
  return ranges::view::iota(vertex(0, graph_), vertex(num_vertices(graph_), graph_));
}

template <class T>
auto Graphadapter<T>::values() const
{
  std::vector<T> tmp;
  for (auto i : boost::vertices(graph_))
    tmp.push_back(i.values());
  return ranges::view::counted(tmp.get(), num_vertices(graph_));
}


template <class T>
auto Graphadapter<T>::values()
{
  std::vector<point_type> tmp;
  std::pair<vertex_iter, vertex_iter> vp = boost::vertices(graph_);
  for (; vp.first != vp.second; ++vp.first)
  {
    *vp.first;
    tmp.push_back(*vp.first);
  }
  return ranges::view::counted(tmp.begin(), num_vertices(graph_));

  //return ranges::view::counted(vp.first.weight, num_vertices(graph_));
}

template <class T>
auto Graphadapter<T>::pixels() const
{
  auto tmp = 0;
  return tmp;
}

template <class T>
auto Graphadapter<T>::pixels()
{
  auto tmp = 0;
  return tmp;
}
