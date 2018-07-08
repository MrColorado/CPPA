#pragma once

#include <range/v3/all.hpp>

template <class T, class Nbh>
class ImageAdapter
{
public:
  using vertex_descriptor = typename T::point_type;

  ImageAdapter(T image, Nbh neighbour);
  auto vertices();
  auto adjacent_vertices(vertex_descriptor v);
  size_t num_vertices();

private:
  T img_;
  Nbh neighbour_;
};

#include "imageadapter.hxx"
