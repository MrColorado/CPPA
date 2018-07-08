#include <range/v3/view/iota.hpp>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/counted.hpp>

#include <vector>
#include <iostream>

template <class T>
Graphadapter<T>::Graphadapter(Graph* graph)
  : graph_(graph)
{
}

template <class T>
const T& Graphadapter<T>::operator()(point_type p) const
{
  return (*graph_)[vertex(p, *graph_)].value_;
}

template <class T>
T& Graphadapter<T>::operator()(point_type p)
{
  return (*graph_)[vertex(p, *graph_)].value_;
}

template <class T>
auto Graphadapter<T>::domain() const
{
  auto first = *vertices(*graph_).first;
  auto second = *vertices(*graph_).second;
  return ranges::view::iota(first, second);
}

template <class T>
auto Graphadapter<T>::values() const
{
  std::vector<point_type> tmp;
  std::pair<vertex_iter, vertex_iter> vp = boost::vertices(*graph_);
  for (; vp.first != vp.second; ++vp.first)
    tmp.push_back((*graph_)[*vp.first].value_);
  return ranges::view::counted(tmp.begin(), tmp.size());
}


template <class T>
auto Graphadapter<T>::values()
{
  std::vector<point_type> tmp;
  std::pair<vertex_iter, vertex_iter> vp = boost::vertices(*graph_);
  for (; vp.first != vp.second; ++vp.first)
    tmp.push_back((*graph_)[*vp.first].value_);
  return ranges::view::counted(tmp.begin(), tmp.size());
}

template <class T>
auto Graphadapter<T>::pixels() const
{
  return ranges::view::zip(domain(), values());
}

template <class T>
auto Graphadapter<T>::pixels()
{
  return ranges::view::zip(domain(), values());
}
