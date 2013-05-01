2D-infinite-map
===============

A module that allow you to use a infinite map in a 2D game.

It use Template for flexibilitie.

You can change the Area size (MAP_AREA_SIZE)
default #define MAP_AREA_SIZE 8//2 4 8 16 32 64 128
You can change it in Area.hpp

Test on Ubuntu x32/x64.




Class
=====

Map<T>
------

T is a tile class.

This is the class that you will use. Use the (int,int) operator to get the tile at this position (can be negative)


Area<T>
-------

T is a tile class.

This class don,t have to be use, but have to be custom (load/unload). It split the word into MAP_AREA_SIZE*MAP_AREA_SIZE zone, and allow you to load/unload this o the fly.


Tile
----

It is the atomic unit af the map (a cell).
You can make your own, but use Tile as base.



Exemple
=======

see main.cpp 
