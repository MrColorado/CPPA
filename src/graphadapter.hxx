#include <range/v3/view/counted.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/zip.hpp>

#include <vector>

template<typename Graph, typename T>
Graphadapter<Graph, T>::Graphadapter(Graph* graph)
  : graph_(graph)
{
}

template<typename Graph, typename T>
const T&
Graphadapter<Graph, T>::operator()(point_type p) const
{
  return (*graph_)[vertex(p, *graph_)];
}

template<typename Graph, typename T>
T&
Graphadapter<Graph, T>::operator()(point_type p)
{
  return (*graph_)[vertex(p, *graph_)];
}

template<typename Graph, typename T>
auto
Graphadapter<Graph, T>::domain() const
{
  auto first = *vertices(*graph_).first;
  auto second = *vertices(*graph_).second;
  return ranges::view::iota(first, second);
}

template<typename Graph, typename T>
auto
Graphadapter<Graph, T>::values() const
{
  std::vector<point_type> tmp;
  std::pair<vertex_iter, vertex_iter> vp = boost::vertices(*graph_);
  for (; vp.first != vp.second; ++vp.first)
    tmp.push_back((*graph_)[*vp.first]);
  return ranges::view::counted(tmp.begin(), tmp.size());
}

template<typename Graph, typename T>
auto
Graphadapter<Graph, T>::values()
{
  std::vector<point_type> tmp;
  std::pair<vertex_iter, vertex_iter> vp = boost::vertices(*graph_);
  for (; vp.first != vp.second; ++vp.first)
    tmp.push_back((*graph_)[*vp.first]);
  return ranges::view::counted(tmp.begin(), tmp.size());
}

template<typename Graph, typename T>
auto
Graphadapter<Graph, T>::pixels() const
{
  return ranges::view::zip(domain(), values());
}

template<typename Graph, typename T>
auto
Graphadapter<Graph, T>::pixels()
{
  return ranges::view::zip(domain(), values());
}
