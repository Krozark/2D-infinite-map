2D-infinite-map
===============

A module that allow you to use a infinite map in a 2D game.

It use Template for flexibilitie.

You can change the Area size (MAP_AREA_SIZE)

Default: #define MAP_AREA_SIZE 8//2 4 8 16 32 64 128

You can change it in Area.hpp

Test on Ubuntu x32/x64.

Depends:
--------

* ResourceManager<K,T>
    * Can be find here: https://github.com/Krozark/ResourceManager


Class
=====

map::Map<T>
------

T is a tile class.

This is the class that you will use. Use the (int,int) operator to get the tile at this position (can be negative)


map::Area<T>
-------

T is a tile class.

This class don,t have to be use, but have to be custom (load/unload). It split the word into MAP_AREA_SIZE*MAP_AREA_SIZE zone, and allow you to load/unload this o the fly.



map::AreaManager>T>
--------------

This class delete the Areas that are not use since a timout (120 sec is default) to free memory.

You d'ont have to use this class, it is use in Map<T>.


map::AreaLoader<T>
-------------

This class load Area from file (see data/map/0,0 for exemple) or from network (TODO).
You don't have to use it (use in Area<T> constructor) but you can customize it to add your own file format.


map::Tile
----

It is the atomic unit af the map (a cell).
You can make your own, but use Tile as base.


cfg::Config
------

This class is juste regroupmenet of static config, you can modify values as you want.


Datas
=====

In this repertory you will fin some datas for test.


map
---
You have a "format" file that define the current file format to use to load Areu from file, and a empty file that just have defaujt coords.

The filename to use is "x,y" where x,x is the coords of a specefique area.

The format to use is like this:
* #comment
* x y VALUES

x,y is the tile coords in the current area.

VALUES is a pair:
* type:value

Acctualy it suport:
* tex:"texture_name.[png/jpg/...]"
* tex:'texture_name.[png/jpg/...]'
* tex:texture_name.[png/jpg/...]
* obj:id (TODO)

tex define the texture to use on the tile. If texture can't be load, default.png is use. All the texture have to be put under cfg::Config::tex_path directory (texture name can contain  subdirectory path).



Exemple
=======

see main.cpp 
