# CPPA's project

## How to run the project

```sh
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./test
```

## Graph Adapter

First you need to specify two templates :
* The kind of graph that you will use
* The type of data stored in vertex

### Methodes avaibles

```cpp
domain() Return a range of points whithin the domain of the picture
values() Return a range of constant values of the picture
values() Return a range of mutable values of the picture
pixels() Return a range of pixels (point + constant value) of the picture
pixels() Return a range of pixels (point + mutable value) of the picture
```

## Image Adapter

You need to provide a picture and a neighbour description needed to get
adjacent vertices.

### Methodes avaibles

```cpp
vertices() Return a range of all vertices.
adjacent_vertices(vertex_descriptor) Return a range of adjacent vertices.
num_vertices() Return the number of vertices.
```

