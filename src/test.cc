#include <iostream>
#include <assert.h>

#include "graphadapter.hh"
#include "test.hh"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, unsigned> ListGraph;
typedef boost::adjacency_matrix<boost::undirectedS, unsigned> MatrixGraph;

void
testMatrix() {
  MatrixGraph graph(4);

  Graphadapter<MatrixGraph, unsigned> adapter(&graph);

  for (auto i : adapter.values())
    assert(i == 0);

  for (unsigned i = 0; i < 4; i++)
  {
    adapter(i) = i;
    assert(adapter(i) == i);
  }

  for (auto i : adapter.values())
    adapter(i) *= 2;

  for (auto i : adapter.pixels())
    assert(2 * i.first == i.second);
}

void
testList() {
  ListGraph graph(4);

  Graphadapter<ListGraph, unsigned> adapter(&graph);

  for (auto i : adapter.values())
    assert(i == 0);

  for (unsigned i = 0; i < 4; i++)
  {
    adapter(i) = i;
    assert(adapter(i) == i);
  }

  for (auto i : adapter.values())
    adapter(i) *= 2;

  for (auto i : adapter.pixels())
    assert(2 * i.first == i.second);
}