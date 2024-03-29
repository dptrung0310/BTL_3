#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED

#include<windows.h>
#include<bits/stdc++.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>

static SDL_Window* g_window=NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int SCREEN_WIDTH=1280;
const int SCREEN_HEIGHT=640;
const int SCREEN_BPP=32;

const int COLOR_KEY_R=167;
const int COLOR_KEY_G=175;
const int COLOR_KEY_B=180;

const int RENDER_DRAW_COLOR=255;


#define TILE_SIZE 64

#define MAX_MAP_X 400
#define MAX_MAP_Y 10

typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};// de xem phim nao duoc su dung

typedef struct Map{
    int start_x;
    int start_y;

    int max_x_;
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    char* file_name_;
};

#endif // COMMONFUNC_H_INCLUDED
