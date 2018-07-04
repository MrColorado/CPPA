template <class T>
Graphadapter<T>::Graphadapter(Graph graph)
{
  graph_ = graph;
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
  auto tmp = 0;
  return tmp;
}

template <class T>
auto Graphadapter<T>::values() const
{
  auto tmp = 0;
  return tmp;
}

template <class T>
auto Graphadapter<T>::values()
{
  auto tmp = 0;
  return tmp;
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
