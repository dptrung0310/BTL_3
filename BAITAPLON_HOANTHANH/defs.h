#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 480;
const char* WINDOW_TITLE = "Run To Die";
#define jump 17
#define SPEED_FALL 1
#define MAX_FALL_SPEED 6
#define BACKGROUND_IMG "img\\forest.png"
#define speed_object 1.5
#define speed_run 4
#define MORE_SPEED_RUN 0.2
#define SCREEN_SCROLL 1
#define xtele 120
#define slash_speed 10

#define MORE_SPEED_NAM 0.3
#define MORE_SPEED_RED_BIRD 0.5
#define MORE_SPEED_BLUE_BIRD 0.4

#define speed_fatbird 1.5
#define MORE_SPEED_FAT_BIRDY 0.2
#define MORE_SPEED_FATBIRD 0.1

#define chieudai_run 25
#define chieucao_run 46

#define chieudai_nhay 21
#define chieucao_nhay 45

#define chieudai_nam 26
#define chieucao_nam 29

#define chieudai_bird 33
#define chieucao_bird 29

#define chieudai_fatbird 33
#define chieucao_fatbird 32

#define hero_run_left_thua 27
#define hero_run_right_thua 24

#define hero_jump_left_thua 13
#define hero_jump_right_thua 11

#define hero_attack_thua 10

#define BIEN_DUOI 340

#define y_huongdan -112
#define x_huongdan 100

#define chieudai_anhhero 96
#define chieucao_anhbird 40
#define chieucao_anhfatbird 48

enum GameState {
    GAME_START,
    GAME_MENU,
    GAME_LOOP,
    GAME_LOOP1,
    GAME_OVER1,
    GAME_OVER
};

//frame hero trang

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

const char* HERO_Left = "img\\Run-Sheet-Left.png";
const int HERO_Left_CLIPS[][4] = {
    {0,0,80,80},
    {80,0,80,80},
    {160,0,80,80},
    {240,0,80,80},
    {320,0,80,80},
    {400,0,80,80},
    {480,0,80,80},
    {560,0,80,80},
};
const int HERO_Left_FRAMES= sizeof(HERO_Left_CLIPS)/sizeof(int)/4;

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

const char* HERO_ATTACK = "img\\Attack-01-Sheet.png";
const int HERO_ATTACK_CLIPS[][4] = {
    {0,0,96,80},
    {96,0,96,80},
    {192,0,96,80},
    {288,0,96,80},
    {384,0,96,80},
    {480,0,96,80},
    {576,0,96,80},
    {672,0,96,80},

};
const int HERO_ATTACK_FRAMES= 8;

const char* HERO_L_RIGHT = "img\\HERO_L_RIGHT.png";
const int HERO_L_RIGHT_CLIPS[][4] = {
    {0,0,96,80},
    {96,0,96,80},
    {192,0,96,80},
    {288,0,96,80},
    {384,0,96,80},

};
const int HERO_L_RIGHT_FRAMES= 5;

const char* HERO_ATTACK_LEFT = "img\\Attack-01-Sheet-Left.png";
const int HERO_ATTACK_LEFT_CLIPS[][4] = {
    {672,0,96,80},
    {576,0,96,80},
    {480,0,96,80},
    {384,0,96,80},
    {288,0,96,80},
    {192,0,96,80},
    {96,0,96,80},
    {0,0,96,80},

};
const int HERO_ATTACK_LEFT_FRAMES= 8;

const char* HERO_L_LEFT = "img\\HERO_L_LEFT.png";
const int HERO_L_LEFT_CLIPS[][4] = {
    {384,0,96,80},
    {288,0,96,80},
    {192,0,96,80},
    {96,0,96,80},
    {0,0,96,80},

};
const int HERO_L_LEFT_FRAMES= 5;

const char* HERO_DEFEND_RIGHT = "img\\defend.png";
const int HERO_DEFEND_RIGHT_CLIPS[][4] = {
    {0,0,96,80},
};
const int HERO_DEFEND_RIGHT_FRAMES= 1;

const char* HERO_DEFEND_LEFT = "img\\defend_left.png";
const int HERO_DEFEND_LEFT_CLIPS[][4] = {
    {0,0,96,80},
};
const int HERO_DEFEND_LEFT_FRAMES= 1;

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

const char* HERO_JUMP_LEFT = "img\\Jump-All-Sheet-Left.png";
const int HERO_JUMP_LEFT_CLIPS[][4] = {
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
const int HERO_JUMP_LEFT_FRAMES= sizeof(HERO_JUMP_LEFT_CLIPS)/sizeof(int)/4;

const char* HERO_STAND = "img\\hero_stand.png";
const int HERO_STAND_CLIPS[][4] = {
    {0,0,64,80},
    {64,0,64,80},
    {128,0,64,80},
    {192,0,64,80},

};
const int HERO_STAND_FRAMES= sizeof(HERO_STAND_CLIPS)/sizeof(int)/4;

const char* HERO_STAND_LEFT = "img\\hero_stand_left.png";
const int HERO_STANDLEFT_CLIPS[][4] = {
    {192,0,64,80},
    {128,0,64,80},
    {64,0,64,80},
    {0,0,64,80},
};
const int HERO_STANDLEFT_FRAMES= sizeof(HERO_STANDLEFT_CLIPS)/sizeof(int)/4;

// hero red
const char* HERO_RED = "img\\Run-Sheet-RED-RIGHT.png";
const int HERO_RED_CLIPS[][4] = {
    {0,0,80,80},
    {80,0,80,80},
    {160,0,80,80},
    {240,0,80,80},
    {320,0,80,80},
    {400,0,80,80},
    {480,0,80,80},
    {560,0,80,80},
};
const int HERO_RED_FRAMES= sizeof(HERO_RED_CLIPS)/sizeof(int)/4;

const char* HERO_RED_Left = "img\\Run-Sheet-RED-LEFT.png";
const int HERO_RED_Left_CLIPS[][4] = {
    {0,0,80,80},
    {80,0,80,80},
    {160,0,80,80},
    {240,0,80,80},
    {320,0,80,80},
    {400,0,80,80},
    {480,0,80,80},
    {560,0,80,80},
};
const int HERO_RED_Left_FRAMES= sizeof(HERO_RED_Left_CLIPS)/sizeof(int)/4;

const char* HERO_RED_DEAD = "img\\Dead-Sheet-RED.png";
const int HERO_RED_DEAD_CLIPS[][4] = {
    {0,0,80,80},
    {80,0,80,80},
    {160,0,80,80},
    {240,0,80,80},
    {320,0,80,80},
    {400,0,80,80},
    {480,0,80,80},
    {560,0,80,80},
};
const int HERO_RED_DEAD_FRAMES= sizeof(HERO_RED_DEAD_CLIPS)/sizeof(int)/4;

const char* HERO_RED_ATTACK = "img\\Attack-01-Sheet-RED-RIGHT.png";
const int HERO_RED_ATTACK_CLIPS[][4] = {
    {0,0,96,80},
    {96,0,96,80},
    {192,0,96,80},
    {288,0,96,80},
    {384,0,96,80},
    {480,0,96,80},
    {576,0,96,80},
    {672,0,96,80},

};
const int HERO_RED_ATTACK_FRAMES= 8;

const char* HERO_RED_L_RIGHT = "img\\HERO_RED_L_RIGHT.png";
const int HERO_RED_L_RIGHT_CLIPS[][4] = {
    {0,0,96,80},
    {96,0,96,80},
    {192,0,96,80},
    {288,0,96,80},
    {384,0,96,80},

};
const int HERO_RED_L_RIGHT_FRAMES= 5;

const char* HERO_RED_ATTACK_LEFT = "img\\Attack-01-Sheet-RED-LEFT.png";
const int HERO_RED_ATTACK_LEFT_CLIPS[][4] = {
    {672,0,96,80},
    {576,0,96,80},
    {480,0,96,80},
    {384,0,96,80},
    {288,0,96,80},
    {192,0,96,80},
    {96,0,96,80},
    {0,0,96,80},

};
const int HERO_RED_ATTACK_LEFT_FRAMES= 8;

const char* HERO_RED_L_LEFT = "img\\HERO_RED_L_LEFT.png";
const int HERO_RED_L_LEFT_CLIPS[][4] = {
    {384,0,96,80},
    {288,0,96,80},
    {192,0,96,80},
    {96,0,96,80},
    {0,0,96,80},

};
const int HERO_RED_L_LEFT_FRAMES= 5;

const char* HERO_RED_DEFEND_RIGHT = "img\\defend-RED-RIGHT.png";
const int HERO_RED_DEFEND_RIGHT_CLIPS[][4] = {
    {0,0,96,80},
};
const int HERO_RED_DEFEND_RIGHT_FRAMES= 1;

const char* HERO_RED_DEFEND_LEFT = "img\\defend-RED-LEFT.png";
const int HERO_RED_DEFEND_LEFT_CLIPS[][4] = {
    {0,0,96,80},
};
const int HERO_RED_DEFEND_LEFT_FRAMES= 1;

const char* HERO_RED_JUMP = "img\\Jump-All-Sheet-RED-RIGHT.png";
const int HERO_RED_JUMP_CLIPS[][4] = {
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
const int HERO_RED_JUMP_FRAMES= sizeof(HERO_RED_JUMP_CLIPS)/sizeof(int)/4;

const char* HERO_RED_JUMP_LEFT = "img\\Jump-All-Sheet-RED-LEFT.png";
const int HERO_RED_JUMP_LEFT_CLIPS[][4] = {
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
const int HERO_RED_JUMP_LEFT_FRAMES= sizeof(HERO_RED_JUMP_LEFT_CLIPS)/sizeof(int)/4;

const char* HERO_RED_STAND = "img\\hero_RED_stand_right.png";
const int HERO_RED_STAND_CLIPS[][4] = {
    {0,0,64,80},
    {64,0,64,80},
    {128,0,64,80},
    {192,0,64,80},

};
const int HERO_RED_STAND_FRAMES= sizeof(HERO_RED_STAND_CLIPS)/sizeof(int)/4;

const char* HERO_RED_STAND_LEFT = "img\\hero_RED_stand_left.png";
const int HERO_RED_STAND_LEFT_CLIPS[][4] = {
    {192,0,64,80},
    {128,0,64,80},
    {64,0,64,80},
    {0,0,64,80},
};
const int HERO_RED_STAND_LEFT_FRAMES= sizeof(HERO_RED_STAND_LEFT_CLIPS)/sizeof(int)/4;


// frame quai

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

const char*  BLUE_BIRD_SPRITE_FILE = "img\\bluebird.png";
const int BLUE_BIRD_CLIPS[][4] = {
    {0, 0, 40, 40},
    {40, 0, 40, 40},
    {80, 0, 40, 40},
    {120, 0, 40, 40},
    {160, 0, 40, 40},
    {200, 0, 40, 40},
    {240, 0, 40, 40},
    {280, 0, 40, 40},
    {320, 0, 40, 40},
};
const int BLUE_BIRD_FRAMES = sizeof(BLUE_BIRD_CLIPS)/sizeof(int)/4;

const char*  FAT_BIRD_SPRITE_FILE = "img\\fatbird.png";
const int FAT_BIRD_CLIPS[][4] = {
    {0, 0, 40, 48},
    {40, 0, 40, 48},
    {80, 0, 40, 48},
    {120, 0, 40, 48},
    {160, 0, 40, 48},
    {200, 0, 40, 48},
    {240, 0, 40, 48},
    {280, 0, 40, 48},

};
const int FAT_BIRD_FRAMES = 8;

const char* NAM="img\\nam.png";
const int NAM_CLIPS[][4] = {
    {0, 0, 40, 40},
};
const int NAM_FRAMES = sizeof(NAM_CLIPS)/sizeof(int)/4;

const char*  EXPLOSION_FILE = "img\\explosion.png";
const int EXPLOSION_CLIPS[][4] = {
    {0, 0, 40, 40},
    {40, 0, 40, 40},
    {80, 0, 40, 40},

    {0, 40, 40, 40},
    {40, 40, 40, 40},
    {80, 40, 40, 40},
};
const int EXPLOSION_FRAMES = sizeof(EXPLOSION_CLIPS)/sizeof(int)/4;

const char*  SMOKE_RIGHT_FILE = "img\\smoke_right.png";
const int SMOKE_RIGHT_CLIPS[][4] = {
    {120, 0, 60 ,60},
    {60, 0, 60 ,60},
    {0, 0, 60 ,60},

    {120, 60, 60 ,60},
    {60, 60, 60 ,60},
    {0, 60, 60 ,60},

};
const int SMOKE_RIGHT_FRAMES = sizeof( SMOKE_RIGHT_CLIPS)/sizeof(int)/4;

const char*  SMOKE_LEFT_FILE = "img\\smoke_left.png";
const int SMOKE_LEFT_CLIPS[][4] = {
    {0, 0, 60 ,60},
    {60, 0, 60 ,60},
    {120, 0, 60 ,60},

    {0, 60, 60 ,60},
    {60, 60, 60 ,60},
    {120, 60, 60 ,60},

};
const int SMOKE_LEFT_FRAMES = sizeof( SMOKE_LEFT_CLIPS)/sizeof(int)/4;

#endif
