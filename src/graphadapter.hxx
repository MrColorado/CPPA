#include <range/v3/view/iota.hpp>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/counted.hpp>

template <typename T>
Graphadapter<T>::Graphadapter(Graph graph)
  : graph_(graph)
{
}

template <typename T>
const T& Graphadapter<T>::operator()(point_type p) const
{
  return graph_[p];
}

template <typename T>
T& Graphadapter<T>::operator()(point_type p)
{
  return graph_[p];
}

template <typename T>
auto Graphadapter<T>::domain() const
{
  return ranges::view::iota(0, num_vertices(graph_));
}

template <typename T>
auto Graphadapter<T>::values() const
{
  auto tmp = 0;
  return tmp;
}

template <typename T>
auto Graphadapter<T>::values()
{
  auto tmp = 0;
  return tmp;
}

template <typename T>
auto Graphadapter<T>::pixels() const
{
  auto tmp = 0;
  return tmp;
}

template <typename T>
auto Graphadapter<T>::pixels()
{
  auto tmp = 0;
  return tmp;
}
