#ifndef MAP_TILE_HPP
#define MAP_TILE_HPP

/* the minimum unit for a map (a cell) */
namespace map
{
    class Tile
    {
        public:
            Tile(const int& X,const int& Y);
            ~Tile();
            Tile(const Tile&) = delete;
            Tile& operator=(const Tile&) = delete;
            
            int x,y;

        private:
        //sprite
    };
};
#endif
