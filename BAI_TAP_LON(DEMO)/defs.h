#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 480;
const char* WINDOW_TITLE = "Hello World!";
#define jump 17
#define SPEED_FALL 1
#define MAX_FALL_SPEED 10
#define BACKGROUND_IMG "img\\forest.png"
#define speed_object 3
#define speed_run 10
#define SCREEN_SCROLL 1
#define MORE_SPEED 0.5
const char* HERO = "img\\Run-Sheet.png";
const int HERO_CLIPS[][4] = {
    {0,0,80,80},
    {80,0,80,80},
    {160,0,80,80},
    {240,0,80,80},
    {320,0,80,80},
    {400,0,80,80},
    {480,0,80,80},
    {560,0,80,80},
};
const int HERO_FRAMES= sizeof(HERO_CLIPS)/sizeof(int)/4;

const char* HERO_DEAD = "img\\Dead-Sheet.png";
const int HERO_DEAD_CLIPS[][4] = {
    {0,0,80,80},
    {80,0,80,80},
    {160,0,80,80},
    {240,0,80,80},
    {320,0,80,80},
    {400,0,80,80},
    {480,0,80,80},
    {560,0,80,80},
};
const int HERO_DEAD_FRAMES= sizeof(HERO_DEAD_CLIPS)/sizeof(int)/4;

const char* HERO_JUMP = "img\\Jump-All-Sheet.png";
const int HERO_JUMP_CLIPS[][4] = {
    {0,0,56,56},
    {56,0,56,56},
    {112,0,56,56},
    {168,0,56,56},
    {224,0,56,56},
    {280,0,56,56},
    {336,0,56,56},
    {392,0,56,56},
    {448,0,56,56},
    {504,0,56,56},
    {560,0,56,56},
    {616,0,56,56},
    {672,0,56,56},
    {728,0,56,56},
    {784,0,56,56},

};
const int HERO_JUMP_FRAMES= sizeof(HERO_JUMP_CLIPS)/sizeof(int)/4;

const char*  BIRD_SPRITE_FILE = "img\\83127-sprite-area-line-animated-bird-film.png";
const int BIRD_CLIPS[][4] = {
    {0, 0, 40, 40},
    {40, 0, 40, 40},
    {80, 0, 40, 40},
    {120, 0, 40, 40},
    {160, 0, 40, 40},

    {0, 40, 40, 40},
    {40, 40, 40, 40},
    {80, 40, 40, 40},
    {120, 40, 40, 40},
    {160, 40, 40, 40},

};
const int BIRD_FRAMES = sizeof(BIRD_CLIPS)/sizeof(int)/4;

const char* NAM="img\\nam.png";
const int NAM_CLIPS[][4] = {
    {0, 0, 40, 40},
};
const int NAM_FRAMES = sizeof(NAM_CLIPS)/sizeof(int)/4;

#endif
