#include <iostream>

#include "Map.hpp"

using namespace map;
using namespace std;

int main(int argc,char* argv[])
{
    cout<<"MAP_AREA_SIZE: "<<MAP_AREA_SIZE<<endl;
    Map<Tile> map_test;
    Tile* T = map_test(0,0);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(1,3);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(4,4);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(-1,-1);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(-12,42);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;


    return 0;
};
