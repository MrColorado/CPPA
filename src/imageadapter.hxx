template <class T, class Nbh>
ImageAdapter<T, Nbh>::ImageAdapter(T image, Nbh neighbour)
  : img_(image)
  , neighbour_(neighbour)
{
}

template <class T, class Nbh>
auto ImageAdapter<T, Nbh>::vertices()
{
  return img_.domain();
}

template <class T, class Nbh>
auto ImageAdapter<T, Nbh>::adjacent_vertices(vertex_descriptor v)
{
  return ranges::view::filter(neighbour_(v),
                              [this](vertex_descriptor n) -> bool {
                                return ranges::find(this->img_.domain(), n);
                              });
}

template <class T, class Nbh>
size_t ImageAdapter<T, Nbh>::num_vertices()
{
  return img_.domain().size();
}
