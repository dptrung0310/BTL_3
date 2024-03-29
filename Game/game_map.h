#ifndef GAME_MAP_H_INCLUDED
#define GAME_MAP_H_INCLUDED

#include"CommonFunc.h"
#include"BaseObject.h"

#define MAX_TILES 20
class TileMat: public BaseObject
{
public:
    TileMat(){;}
    ~TileMat(){;}
};

class GameMap
{
public:
    GameMap(){;}
    ~GameMap(){;}

    void LoadMap(char * name);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);
private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];// Toi da co 20 dang map trong game cua minh

};

#endif // GAME_MAP_H_INCLUDED
