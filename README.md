# CPPA's project

## How to run the project

```
mkdir build
cd build
cmake RELEASE ..
./test
```

## Graph Adapter

First you need to specify two templates :
* The kind of graph that you will use
* The type of data stored in vertex

### Methodes avaibles

```
domain() Retourne une Range des points du domaine de l'image
values() Retourne une Range de valeurs constantes de l'image
values() Retourne une Range de valeurs mutables de l'image
pixels() Retourne une Range des pixels (point+valeur constantes) d'une image
pixels() Retourne une Range des pixels (point+valeur mutables) d'une image
```

## Image Adapter