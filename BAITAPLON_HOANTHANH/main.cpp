#include <iostream>
#include "graphics.h"
#include "defs.h"

using namespace std;

bool checkOnGround(int y){
    if(y==BIEN_DUOI) return true;
    return false;
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Graphics graphics;
    graphics.init();

    Mix_Music *gMusic = graphics.loadMusic("assets\\tiengtrongtudo.mp3");
    Mix_Chunk *gJump = graphics.loadSound("assets\\7M5K8H4-wizard-jumping-jump.wav");
    Mix_Chunk *gattack=graphics.loadSound("assets\\L8SWRY6-sword-attack.wav");
    Mix_Chunk* gPress=graphics.loadSound("assets\\4ASN3CU-button-press-44324.wav");
    Mix_Chunk* gTele=graphics.loadSound("assets\\telesound.wav");


    Mix_VolumeChunk(gJump,MIX_MAX_VOLUME*0.2);
    Mix_VolumeChunk(gattack,MIX_MAX_VOLUME*0.3);
    Mix_VolumeChunk(gPress,MIX_MAX_VOLUME*0.3);
    Mix_VolumeChunk(gTele,MIX_MAX_VOLUME*0.3);

    SDL_Texture* sound_on= graphics.loadTexture("img\\sound_on.png");
    SDL_Texture* sound_off= graphics.loadTexture("img\\sound_off.png");
    SDL_Texture* sound_on_small= graphics.loadTexture("img\\sound_on_small.png");
    SDL_Texture* sound_off_small= graphics.loadTexture("img\\sound_off_small.png");

    SDL_Texture* khung_hp_left = graphics.loadTexture("img\\hp_khung_left.png");
    float xkhunghp_left = 0;
    float ykhunghp_left = 44;
    SDL_Texture* hp_left = graphics.loadTexture("img\\hp_left.png");
    float xhp_left = 0;
    float yhp_left = 45;
    SDL_Texture* khung_hp_right = graphics.loadTexture("img\\hp_khung_right.png");
    float xkhunghp_right = SCREEN_WIDTH - 362;
    float ykhunghp_right = 44;
    SDL_Texture* hp_right = graphics.loadTexture("img\\hp_right.png");
    float xhp_right = SCREEN_WIDTH - 360;
    float yhp_right = 45;

    SDL_Texture* khungnangluong = graphics.loadTexture("img\\khungnangluong.png");
    float xkhungenergy = 0;
    float ykhungenergy = 69;
    SDL_Texture* energy = graphics.loadTexture("img\\energy.png");
    float xenergy = -300;
    float yenergy = 70;
    SDL_Texture* khungnangluong_red = graphics.loadTexture("img\\khungnangluong_red.png");
    float xkhungenergy_red = SCREEN_WIDTH - 301;
    float ykhungenergy_red = 69;
    float xenergy_red = SCREEN_WIDTH;
    float yenergy_red = 70;

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));
    SDL_Texture* huongdan1=graphics.loadTexture("img\\huongdan1.png");
    float xhuongdan1=-400;
    float yhuongdan1=80;

    SDL_Texture* heart = graphics.loadTexture("img\\heart.png");

    int somang=3;
    float kcheart=180;
    float kcheart2=215;
    float kcheart3=250;

    SDL_Texture* huongdanchimdo=graphics.loadTexture("img\\huongdanchimdo.png");
    float xhuongdan2=-400;
    float yhuongdan2=80;

    SDL_Texture* huongdanchimxanh=graphics.loadTexture("img\\huongdanchimxanh.png");
    float xhuongdan3=-400;
    float yhuongdan3=80;

    SDL_Texture* huongdanchimbeo=graphics.loadTexture("img\\huongdanchimbeo.png");
    float xhuongdan4=-400;
    float yhuongdan4=80;

    SDL_Texture* huongdanattack=graphics.loadTexture("img\\huongdanattack.png");
    float xhuongdan5=-400;
    float yhuongdan5=80;

//HERO_TRANG

    Sprite hero;
    SDL_Texture* heroTexture = graphics.loadTexture(HERO);
    SDL_Texture* heroleftTexture = graphics.loadTexture(HERO_Left);
    hero.x = 5;
    hero.y = 5;

    SDL_Texture* herojumpTexture=graphics.loadTexture(HERO_JUMP);
    SDL_Texture* herojumpLeftTexture=graphics.loadTexture(HERO_JUMP_LEFT);

    SDL_Texture* heroDeadTexture=graphics.loadTexture(HERO_DEAD);

    SDL_Texture* heroattackTexture=graphics.loadTexture(HERO_ATTACK);
    SDL_Texture* heroattackLeftTexture=graphics.loadTexture(HERO_ATTACK_LEFT);

    SDL_Texture* herostandTexture = graphics.loadTexture(HERO_STAND);
    SDL_Texture* herostandLeftTexture = graphics.loadTexture(HERO_STAND_LEFT);

    SDL_Texture* herodefendTexture = graphics.loadTexture(HERO_DEFEND_RIGHT);
    SDL_Texture* herodefendleftTexture = graphics.loadTexture(HERO_DEFEND_LEFT);

    SDL_Texture* heroLrightTexture = graphics.loadTexture(HERO_L_RIGHT);
    SDL_Texture* skill_L_right = graphics.loadTexture("img\\Circular.png");
    vector<Chems> slashright;

    SDL_Texture* heroLleftTexture = graphics.loadTexture(HERO_L_LEFT);
    SDL_Texture* skill_L_left = graphics.loadTexture("img\\Circular_left.png");
    vector<Chems> slashleft;

    vector<Sprite*> smokeright;
    vector<Sprite*> smokeleft;

//HERO_RED

    Sprite hero_red;
    SDL_Texture* hero_redTexture = graphics.loadTexture(HERO_RED);
    SDL_Texture* hero_redleftTexture = graphics.loadTexture(HERO_RED_Left);
    hero_red.x = 950;
    hero_red.y = 5;

    SDL_Texture* hero_redjumpTexture=graphics.loadTexture(HERO_RED_JUMP);
    SDL_Texture* hero_redjumpLeftTexture=graphics.loadTexture(HERO_RED_JUMP_LEFT);

    SDL_Texture* hero_redDeadTexture=graphics.loadTexture(HERO_RED_DEAD);

    SDL_Texture* hero_redattackTexture=graphics.loadTexture(HERO_RED_ATTACK);
    SDL_Texture* hero_redattackLeftTexture=graphics.loadTexture(HERO_RED_ATTACK_LEFT);

    SDL_Texture* hero_redstandTexture = graphics.loadTexture(HERO_RED_STAND);
    SDL_Texture* hero_redstandLeftTexture = graphics.loadTexture(HERO_RED_STAND_LEFT);

    SDL_Texture* hero_reddefendTexture = graphics.loadTexture(HERO_RED_DEFEND_RIGHT);
    SDL_Texture* hero_reddefendleftTexture = graphics.loadTexture(HERO_RED_DEFEND_LEFT);

    SDL_Texture* hero_redLrightTexture = graphics.loadTexture(HERO_RED_L_RIGHT);
    SDL_Texture* skill_red_L_right = graphics.loadTexture("img\\Circular_RED_RIGHT.png");
    vector<Chems> slashright_red;

    SDL_Texture* hero_redLleftTexture = graphics.loadTexture(HERO_RED_L_LEFT);
    SDL_Texture* skill_red_L_left = graphics.loadTexture("img\\Circular_RED_LEFT.png");
    vector<Chems> slashleft_red;

    vector<Sprite*> smokeright_red;
    vector<Sprite*> smokeleft_red;

    // ...........................................................

    SDL_Texture* buttonplaywhite=graphics.loadTexture("img\\Playnowwhite.png");
    SDL_Texture* buttonplayblack=graphics.loadTexture("img\\Playnowblack.png");
    SDL_Texture* titlegame=graphics.loadTexture("img\\titlegame.png");
    SDL_Texture* signgame=graphics.loadTexture("img\\signed.png");

    SDL_Texture* classicmode=graphics.loadTexture("img\\classicmode.png");
    SDL_Texture* solomode=graphics.loadTexture("img\\solomode.png");

    SDL_Texture* pause = graphics.loadTexture("img\\PAUSE.png");
    SDL_Texture* pause_small = graphics.loadTexture("img\\PAUSE_SMALL.png");

    TTF_Font* efont = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",70 );
    SDL_Color ecolor = {255, 239, 63, 0};
    SDL_Color ecolor2 = {0, 0, 0, 0};

    TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",40 );
    SDL_Color color = {255, 255, 0, 0};

    SDL_Texture* helloText = graphics.renderText("Run To Die", efont, ecolor);
    SDL_Texture* helloText2 = graphics.renderText("Run To Die", efont, ecolor2);

    Sprite nam1;
    Sprite nam2;
    SDL_Texture* treeTexture = graphics.loadTexture("img\\nam.png");
    SDL_Texture* treeTexture2 = graphics.loadTexture("img\\nam.png");
    nam1.init(treeTexture,NAM_FRAMES,NAM_CLIPS);
    nam2.init(treeTexture2,NAM_FRAMES,NAM_CLIPS);
    nam1.x = SCREEN_WIDTH;
    nam1.y = 370;
    nam2.x = SCREEN_WIDTH + SCREEN_WIDTH/2;
    nam2.y = 370;


    Sprite redbird;
    SDL_Texture* redbirdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    redbird.init(redbirdTexture,BIRD_FRAMES,BIRD_CLIPS);
    redbird.x = nam1.x + SCREEN_WIDTH/3;
    redbird.y = SCREEN_HEIGHT/2;

    Sprite bluebird;
    SDL_Texture* bluebirdTexture= graphics.loadTexture(BLUE_BIRD_SPRITE_FILE);
    bluebird.init(bluebirdTexture,BLUE_BIRD_FRAMES,BLUE_BIRD_CLIPS);
    bluebird.x = nam2.x + SCREEN_WIDTH/3;
    bluebird.y = SCREEN_HEIGHT/2;

    Sprite fatbird;
    SDL_Texture* fatbirdTexture = graphics.loadTexture(FAT_BIRD_SPRITE_FILE);
    fatbird.init(fatbirdTexture,FAT_BIRD_FRAMES,FAT_BIRD_CLIPS);
    fatbird.x=SCREEN_WIDTH/2.5;
    fatbird.y=-chieucao_fatbird;

    vector<Sprite*> vunolon;

    float screenscroll=SCREEN_SCROLL;
    float more_speed_redbird=0;
    float more_speed_bluebird=0;
    float more_speed_nam=0;
    float more_speed_run=0;
    float more_speed_fatbirdx=0;
    float more_speed_fatbirdy=0;
    int luotchem=0;
    int current_frame_dead = 0;

    SDL_Texture* gameover = graphics.loadTexture("img\\gameover.png");
    SDL_Texture* restartwhite= graphics.loadTexture("img\\restartwhite.png");
    SDL_Texture* restartblack= graphics.loadTexture("img\\restartblack.png");
    SDL_Texture* quitwhite= graphics.loadTexture("img\\quitwhite.png");
    SDL_Texture* quitblack= graphics.loadTexture("img\\quitblack.png");

    SDL_Texture* player1win = graphics.loadTexture("img\\player1win.png");
    SDL_Texture* player2win = graphics.loadTexture("img\\player2win.png");

    GameState game_state = GAME_START;

    int a,b;
    int diem=0;

    int soHD = 5;
    bool checkHD1=false;
    bool checkHD2=false;
    bool checkHD3=false;
    bool checkHD4=false;
    bool checkHD5=false;

    bool screenscrollIncreased = false;

    bool pausing=false;
    bool pausesound = false;

    bool quit=false;
    SDL_Event e;
    while(!quit){
        switch (game_state)
        {
        case GAME_START:
        {
                SDL_GetMouseState(&a,&b);
                while(SDL_PollEvent(&e)){
                    if(e.type==SDL_MOUSEBUTTONDOWN && (a>320&&a<620&&b>320&&b<387))
                    {
                        graphics.play(gPress);
                        game_state=GAME_MENU;
                    }
                    else if (e.type==SDL_QUIT)
                    {
                        quit = true;
                    }
                }

                background.scroll(1);
                graphics.renderbackgr(background);
                //button
                if(a>320&&a<620&&b>320&&b<387)
                {
                    graphics.renderTexture(buttonplaywhite,330,320);
                }
                else graphics.renderTexture(buttonplayblack,330,320);
                //Text
                graphics.renderTexture(titlegame,240,110);
                graphics.renderTexture(signgame,620,130);

                graphics.renderTexture(helloText2, 313, 142);
                graphics.renderTexture(helloText, 315, 140);

                //hero
                hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);
                hero.tick();
                graphics.render(440,230,hero);
                graphics.presentScene();
                SDL_Delay(20);
                break;
        }
        case GAME_MENU:
        {
            graphics.renderbackgr(background);
            while(SDL_PollEvent(&e)){
                    SDL_GetMouseState(&a,&b);
                    if(e.type==SDL_MOUSEBUTTONDOWN && (330<=a && a<=330 + 300   &&b>=230&&b<=297))
                    {
                        graphics.play(gPress);
                        game_state=GAME_LOOP;
                    }
                    else if(e.type==SDL_MOUSEBUTTONDOWN && (a>320&&a<620&&b>320&&b<387))
                    {
                        graphics.play(gPress);
                        game_state=GAME_LOOP1;
                    }
                    else if (e.type==SDL_QUIT)
                    {
                        quit = true;
                    }
            }
             graphics.renderTexture(solomode,330,320);
             graphics.renderTexture(classicmode,330,230);
             graphics.presentScene();
             SDL_Delay(20);
             break;

        }
        case GAME_LOOP1:{
                SDL_PollEvent(&e);
                graphics.renderbackgr(background);

                if(e.type == SDL_QUIT) quit=true;

                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                const Uint8* currentKeyStates_red = SDL_GetKeyboardState(NULL);
                if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
                    switch (e.key.keysym.sym) {
                        case SDLK_d:
                            hero.run_right = (e.type == SDL_KEYDOWN);
                            break;
                        case SDLK_a:
                            hero.run_left = (e.type == SDL_KEYDOWN);
                            break;
                    }
                }

                if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
                    switch (e.key.keysym.sym) {
                        case SDLK_RIGHT:
                            hero_red.run_right = (e.type == SDL_KEYDOWN);
                            break;
                        case SDLK_LEFT:
                            hero_red.run_left = (e.type == SDL_KEYDOWN);
                            break;
                    }
                }

                //smk_right
                if (e.type == SDL_KEYDOWN && !hero.is_defend && xenergy>=-250) {
                    switch (e.key.keysym.sym) {
                        case SDLK_k:
                            if(!hero.is_tele && hero.right){
                            graphics.play(gTele);
                            Sprite* smoke_right = new Sprite;
                            SDL_Texture* smokerightTexture = graphics.loadTexture(SMOKE_RIGHT_FILE);
                            smoke_right-> init(smokerightTexture, SMOKE_RIGHT_FRAMES, SMOKE_RIGHT_CLIPS);
                            smoke_right->x = hero.x;
                            smoke_right->y = hero.y + 17;
                            smoke_right->currentFrame = 0;
                            smokeright.push_back(smoke_right);
                            }
                            break;
                    }
                } else if(e.type == SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_k:
                            hero.is_tele = true;
                            break;
                    }
                }
                if (e.type == SDL_KEYDOWN && !hero.is_defend&& xenergy >=-250) {
                    switch (e.key.keysym.sym) {
                        case SDLK_k:
                            if(!hero.is_tele && hero.left){
                            graphics.play(gTele);
                            Sprite* smoke_left = new Sprite;
                            SDL_Texture* smokeleftTexture = graphics.loadTexture(SMOKE_LEFT_FILE);
                            smoke_left-> init(smokeleftTexture, SMOKE_LEFT_FRAMES, SMOKE_LEFT_CLIPS);
                            smoke_left->x = hero.x ;
                            smoke_left->y = hero.y +17 ;
                            smoke_left->currentFrame = 0;
                            smokeleft.push_back(smoke_left);
                            }
                            break;
                    }
                } else if(e.type == SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_k:
                            hero.is_tele = true;
                            break;
                    }
                }

                // ............. red
                if (e.type == SDL_KEYDOWN && !hero_red.is_defend && xenergy_red<=SCREEN_WIDTH - 50) {
                    switch (e.key.keysym.sym) {
                        case SDLK_KP_2:
                            if(!hero_red.is_tele && hero_red.right){
                            graphics.play(gTele);
                            Sprite* smoke_right = new Sprite;
                            SDL_Texture* smokerightTexture = graphics.loadTexture(SMOKE_RIGHT_FILE);
                            smoke_right-> init(smokerightTexture, SMOKE_RIGHT_FRAMES, SMOKE_RIGHT_CLIPS);
                            smoke_right->x = hero_red.x;
                            smoke_right->y = hero_red.y + 17;
                            smoke_right->currentFrame = 0;
                            smokeright_red.push_back(smoke_right);
                            }
                            break;
                    }
                } else if(e.type == SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_KP_2:
                            hero_red.is_tele = true;
                            break;
                    }
                }
                if (e.type == SDL_KEYDOWN && !hero_red.is_defend&& xenergy_red<=SCREEN_WIDTH - 50) {
                    switch (e.key.keysym.sym) {
                        case SDLK_KP_2:
                            if(!hero_red.is_tele && hero_red.left){
                            graphics.play(gTele);
                            Sprite* smoke_left = new Sprite;
                            SDL_Texture* smokeleftTexture = graphics.loadTexture(SMOKE_LEFT_FILE);
                            smoke_left-> init(smokeleftTexture, SMOKE_LEFT_FRAMES, SMOKE_LEFT_CLIPS);
                            smoke_left->x = hero_red.x ;
                            smoke_left->y = hero_red.y +17 ;
                            smoke_left->currentFrame = 0;
                            smokeleft_red.push_back(smoke_left);
                            }
                            break;
                    }
                } else if(e.type == SDL_KEYUP)
                {
                    switch (e.key.keysym.sym){
                        case SDLK_KP_2:
                            hero_red.is_tele = true;
                            break;
                    }
                }

            // .............................
                graphics.play(gMusic);
                SDL_GetMouseState(&a,&b);
                if((a>SCREEN_WIDTH/2 - 50&&a<SCREEN_WIDTH/2 +50 &&b>10&&b<32)&&e.type==SDL_MOUSEBUTTONUP)
                {
                    graphics.play(gPress);
                    pausing = true;

                    while(pausing)
                    {
                        SDL_Event eve;
                        SDL_PollEvent(&eve);
                        if((a>SCREEN_WIDTH/2 - 50&&a<SCREEN_WIDTH/2 +50 &&b>10&&b<32)&&eve.type==SDL_MOUSEBUTTONUP)
                        {
                            graphics.play(gPress);
                            pausing = false;
                        }
                    }
                }
                if(pausesound)
                {
                    Mix_VolumeMusic(0);
                    Mix_VolumeChunk(gattack,0);
                    Mix_VolumeChunk(gPress,0);
                    Mix_VolumeChunk(gJump,0);
                }
                else{
                    Mix_VolumeMusic(SDL_MIX_MAXVOLUME);
                    Mix_VolumeChunk(gattack,SDL_MIX_MAXVOLUME/5);
                    Mix_VolumeChunk(gPress,SDL_MIX_MAXVOLUME/5);
                    Mix_VolumeChunk(gJump,SDL_MIX_MAXVOLUME/6);
                }

                if(!pausesound&&(a>SCREEN_WIDTH/2 -25 && a<SCREEN_WIDTH/2 + 25 && b>33&&b<70)&&e.type == SDL_MOUSEBUTTONDOWN)
                {
                    pausesound=true;
                }
                else if(pausesound&&(a>SCREEN_WIDTH/2 -25 && a<SCREEN_WIDTH/2 + 25 && b>33&&b<70 )&&e.type == SDL_MOUSEBUTTONDOWN)
                {
                    pausesound = false;
                }

                if(!pausesound)
                {
                    graphics.renderTexture(sound_on_small,SCREEN_WIDTH/2 - 25,33);
                }
                else if(pausesound)
                {
                    graphics.renderTexture(sound_off_small,SCREEN_WIDTH/2 -25 ,33);
                }
                graphics.renderTexture(pause_small,SCREEN_WIDTH/2 - 50, 10);
                //.............

                if((currentKeyStates[SDL_SCANCODE_SPACE]||currentKeyStates[SDL_SCANCODE_W])&&checkOnGround(hero.y))
                {
                    graphics.play(gJump);
                }
                if((currentKeyStates_red[SDL_SCANCODE_KP_0]||currentKeyStates_red[SDL_SCANCODE_UP])&&checkOnGround(hero.y))
                {
                    graphics.play(gJump);
                }
                // ..........

                if(!hero.is_defend && currentKeyStates[SDL_SCANCODE_J] && !hero.click ){
                    graphics.play(gattack);
                    hero.click = true;
                    hero.currentFrame=0;
                }
                if(!hero_red.is_defend && currentKeyStates_red[SDL_SCANCODE_KP_1] && !hero_red.click ){
                    graphics.play(gattack);
                    hero_red.click = true;
                    hero_red.currentFrame=0;
                }
                //.............

                //hp
                graphics.renderTexture(hp_left,xhp_left,yhp_left);
                graphics.renderTexture(hp_right,xhp_right,yhp_right);
                graphics.renderTexture(khung_hp_left,xkhunghp_left,ykhunghp_left);
                graphics.renderTexture(khung_hp_right,xkhunghp_right,ykhunghp_right);

                //energy
                graphics.renderTextureenergy(energy,xenergy,yenergy);
                graphics.renderTextureenergy_red(energy,xenergy_red,yenergy_red);
                graphics.renderTexture(khungnangluong,xkhungenergy, ykhungenergy);
                graphics.renderTexture(khungnangluong_red,xkhungenergy_red, ykhungenergy_red);

                //press L

                if(!hero.is_defend && currentKeyStates[SDL_SCANCODE_L] && !hero.click && !hero.skillL&& xenergy>=-230){
                    graphics.play(gattack);
                    hero.skillL = true;
                    Chems ct(hero.x,hero.y);
                    if(hero.right) slashright.push_back(ct);
                    else slashleft.push_back(ct);
                    xenergy -=80;
                    hero.currentFrame=0;
                }

                for(auto &ct:slashright)
                {
                        graphics.renderTexture(skill_L_right,ct.x,ct.y);
                        ct.runright();
                        ct.checkslashright(hero_red,xhp_right);
                }

                 for(auto &ct:slashleft)
                {
                        graphics.renderTexture(skill_L_left,ct.x,ct.y);
                        ct.runleft();
                        ct.checkslashleft(hero_red,xhp_right);
                }
                //red
                if(!hero_red.is_defend && currentKeyStates_red[SDL_SCANCODE_KP_3] && !hero_red.click && !hero_red.skillL&& xenergy_red<=SCREEN_WIDTH - 70){
                    graphics.play(gattack);
                    hero_red.skillL = true;
                    Chems ct(hero_red.x,hero_red.y);
                    if(hero_red.right) slashright_red.push_back(ct);
                    else slashleft_red.push_back(ct);
                    xenergy_red +=70;
                    hero_red.currentFrame=0;
                }

                for(auto &ct:slashright_red)
                {
                        graphics.renderTexture(skill_red_L_right,ct.x,ct.y);
                        ct.runright();
                        ct.checkslashright_red(hero,xhp_left);
                }

                 for(auto &ct:slashleft_red)
                {
                        graphics.renderTexture(skill_red_L_left,ct.x,ct.y);
                        ct.runleft();
                        ct.checkslashleft_red(hero,xhp_left);

                }
                //...........

                //defend
                if(e.type==SDL_KEYDOWN && !hero.click && hero.right)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_s:
                            hero.init(herodefendTexture,HERO_DEFEND_RIGHT_FRAMES,HERO_DEFEND_RIGHT_CLIPS);
                            hero.is_defend = true;
                            break;
                    }
                }
                else if (e.type==SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_s:
                            hero.is_defend = false;
                            break;
                    }
                }
                if(e.type==SDL_KEYDOWN && !hero.click && !hero.skillL && hero.left)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_s:
                            hero.init(herodefendleftTexture,HERO_DEFEND_LEFT_FRAMES,HERO_DEFEND_LEFT_CLIPS);
                            hero.is_defend = true;
                            break;
                    }
                }
                else if (e.type==SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_s:
                            hero.is_defend = false;
                            break;
                    }
                }
                //red
                if(e.type==SDL_KEYDOWN && !hero_red.click && hero_red.right)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_DOWN:
                            hero_red.init(hero_reddefendTexture,HERO_RED_DEFEND_RIGHT_FRAMES,HERO_RED_DEFEND_RIGHT_CLIPS);
                            hero_red.is_defend = true;
                            break;
                    }
                }
                else if (e.type==SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_DOWN:
                            hero_red.is_defend = false;
                            break;
                    }
                }
                if(e.type==SDL_KEYDOWN && !hero_red.click && !hero_red.skillL && hero_red.left)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_DOWN:
                            hero_red.init(hero_reddefendleftTexture,HERO_RED_DEFEND_LEFT_FRAMES,HERO_RED_DEFEND_LEFT_CLIPS);
                            hero_red.is_defend = true;
                            break;
                    }
                }
                else if (e.type==SDL_KEYUP)
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_DOWN:
                            hero_red.is_defend = false;
                            break;
                    }
                }
                // ..............


    if(!hero.is_defend){

                if(hero.click && hero.right)
                {
                    hero.init(heroattackTexture, HERO_ATTACK_FRAMES, HERO_ATTACK_CLIPS);
                    hero.is_attack = true;
                    hero.is_run = false;
                    hero.is_stand = false;
                    hero.is_jump = false;
                }
                else if(hero.click && hero.left)
                {
                    hero.init(heroattackLeftTexture, HERO_ATTACK_LEFT_FRAMES, HERO_ATTACK_LEFT_CLIPS);
                    hero.is_attack = true;
                    hero.is_run = false;
                    hero.is_stand = false;
                    hero.is_jump = false;
                }
                else if(hero.skillL && hero.right)
                {
                    hero.init(heroLrightTexture,HERO_L_RIGHT_FRAMES,HERO_L_RIGHT_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = false;
                    hero.is_stand = false;
                    hero.is_jump = false;
                }
                else if(hero.skillL && hero.left)
                {
                    hero.init(heroLleftTexture,HERO_L_LEFT_FRAMES,HERO_L_LEFT_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = false;
                    hero.is_stand = false;
                    hero.is_jump = false;
                }
                else if(!checkOnGround(hero.y) && hero.right)
                {
                    hero.init(herojumpTexture, HERO_JUMP_FRAMES, HERO_JUMP_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = false;
                    hero.is_stand = false;
                    hero.is_jump = true;
                }
                else if(!checkOnGround(hero.y) && hero.left){
                    hero.init(herojumpLeftTexture, HERO_JUMP_LEFT_FRAMES, HERO_JUMP_LEFT_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = false;
                    hero.is_stand = false;
                    hero.is_jump = true;
                }
                else if(hero.run_right)
                {
                    hero.right = true;
                    hero.left = false;
                    hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = true;
                    hero.is_stand = false;
                    hero.is_jump = false;
                }
                else if(hero.run_left)
                {
                    hero.right = false;
                    hero.left = true;
                    hero.init(heroleftTexture,HERO_Left_FRAMES, HERO_Left_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = true;
                    hero.is_stand = false;
                    hero.is_jump = false;
                }
                else if(hero.left && !hero.click && !hero.skillL)
                {
                    hero.init(herostandLeftTexture, HERO_STANDLEFT_FRAMES, HERO_STANDLEFT_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = false;
                    hero.is_stand = true;
                    hero.is_jump = false;
                }
                else if (hero.right && !hero.click && !hero.skillL)
                {
                    hero.init(herostandTexture, HERO_STAND_FRAMES, HERO_STAND_CLIPS);
                    hero.is_attack = false;
                    hero.is_run = false;
                    hero.is_stand = true;
                    hero.is_jump = false;
                }

                if(hero.click && hero.currentFrame==7) {
                    hero.click=false;
                }
                if(hero.skillL && hero.currentFrame == 4)
                {
                    hero.skillL = false;
                }
                if(xenergy>=-250)
                {
                    hero.tele(e,xenergy);
                }
                hero.attack_hero_red(hero_red,currentKeyStates,xhp_right,xenergy_red,xenergy);
            }
                hero.tick();
                graphics.DoPlayer(hero.x, hero.y, hero, currentKeyStates, more_speed_run);
                graphics.move(hero.x, hero.y, hero);
        // red
        if(!hero_red.is_defend){

                if(hero_red.click && hero_red.right)
                {
                    hero_red.init(hero_redattackTexture, HERO_RED_ATTACK_FRAMES, HERO_RED_ATTACK_CLIPS);
                    hero_red.is_attack = true;
                    hero_red.is_run = false;
                    hero_red.is_stand = false;
                    hero_red.is_jump = false;
                }
                else if(hero_red.click && hero_red.left)
                {
                    hero_red.init(hero_redattackLeftTexture, HERO_RED_ATTACK_LEFT_FRAMES, HERO_RED_ATTACK_LEFT_CLIPS);
                    hero_red.is_attack = true;
                    hero_red.is_run = false;
                    hero_red.is_stand = false;
                    hero_red.is_jump = false;
                }
                else if(hero_red.skillL && hero_red.right)
                {
                    hero_red.init(hero_redLrightTexture,HERO_RED_L_RIGHT_FRAMES,HERO_RED_L_RIGHT_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = false;
                    hero_red.is_stand = false;
                    hero_red.is_jump = false;
                }
                else if(hero_red.skillL && hero_red.left)
                {
                    hero_red.init(hero_redLleftTexture,HERO_RED_L_LEFT_FRAMES,HERO_RED_L_LEFT_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = false;
                    hero_red.is_stand = false;
                    hero_red.is_jump = false;
                }
                else if(!checkOnGround(hero_red.y) && hero_red.right)
                {
                    hero_red.init(hero_redjumpTexture, HERO_RED_JUMP_FRAMES, HERO_RED_JUMP_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = false;
                    hero_red.is_stand = false;
                    hero_red.is_jump = true;
                }
                else if(!checkOnGround(hero_red.y) && hero_red.left){
                     hero_red.init(hero_redjumpLeftTexture, HERO_RED_JUMP_LEFT_FRAMES, HERO_RED_JUMP_LEFT_CLIPS);
                     hero_red.is_attack = true;
                    hero_red.is_run = false;
                    hero_red.is_stand = false;
                    hero_red.is_jump = true;
                }
                else if(hero_red.run_right)
                {
                    hero_red.right = true;
                    hero_red.left = false;
                    hero_red.init(hero_redTexture, HERO_RED_FRAMES, HERO_RED_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = true;
                    hero_red.is_stand = false;
                    hero_red.is_jump = false;
                }
                else if(hero_red.run_left)
                {
                    hero_red.right = false;
                    hero_red.left = true;
                    hero_red.init(hero_redleftTexture,HERO_RED_Left_FRAMES, HERO_RED_Left_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = true;
                    hero_red.is_stand = false;
                    hero_red.is_jump = false;
                }
                else if(hero_red.left && !hero_red.click && !hero_red.skillL)
                {
                    hero_red.init(hero_redstandLeftTexture, HERO_RED_STAND_LEFT_FRAMES, HERO_RED_STAND_LEFT_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = false;
                    hero_red.is_stand = true;
                    hero_red.is_jump = false;
                }
                else if (hero_red.right)
                {
                    hero_red.init(hero_redstandTexture, HERO_RED_STAND_FRAMES, HERO_RED_STAND_CLIPS);
                    hero_red.is_attack = false;
                    hero_red.is_run = false;
                    hero_red.is_stand = true;
                    hero_red.is_jump = false;
                }

                if(hero_red.click && hero_red.currentFrame==7) {
                    hero_red.click=false;
                }
                if(hero_red.skillL && hero_red.currentFrame == 4)
                {
                    hero_red.skillL = false;
                }
                if(xenergy_red<=SCREEN_WIDTH - 50)
                {
                    hero_red.tele_red(e,xenergy_red);
                }
                hero_red.heroredattack(hero,currentKeyStates_red,xhp_left,xenergy , xenergy_red);
            }
                hero_red.tick();
                graphics.DoPlayer_red(hero_red.x, hero_red.y, hero_red, currentKeyStates_red, more_speed_run);
                graphics.move_red(hero_red.x, hero_red.y, hero_red);

    // ..........................................


                for(int i=0 ; i<smokeright.size() ;i++)
                {
                        Sprite* smoke_right = smokeright[i];
                        if(smoke_right!=nullptr)
                        {
                            smoke_right->tick();
                            graphics.render(smoke_right->x,smoke_right->y,*smoke_right);
                            if(smoke_right->currentFrame == 5)
                            {
                                smokeright.erase(smokeright.begin()+i);
                            }
                        }
                }
                for(int i=0 ; i<smokeleft.size() ;i++)
                {
                        Sprite* smoke_left = smokeleft[i];
                        if(smoke_left!=nullptr)
                        {
                            smoke_left->tick();
                            graphics.render(smoke_left->x,smoke_left->y,*smoke_left);
                            if(smoke_left->currentFrame == 5)
                            {
                                smokeleft.erase(smokeleft.begin()+i);
                            }
                        }
                }
                //red
                for(int i=0 ; i<smokeright_red.size() ;i++)
                {
                        Sprite* smoke_right = smokeright_red[i];
                        if(smoke_right!=nullptr)
                        {
                            smoke_right->tick();
                            graphics.render(smoke_right->x,smoke_right->y,*smoke_right);
                            if(smoke_right->currentFrame == 5)
                            {
                                smokeright_red.erase(smokeright_red.begin()+i);
                            }
                        }
                }
                for(int i=0 ; i<smokeleft_red.size() ;i++)
                {
                        Sprite* smoke_left = smokeleft_red[i];
                        if(smoke_left!=nullptr)
                        {
                            smoke_left->tick();
                            graphics.render(smoke_left->x,smoke_left->y,*smoke_left);
                            if(smoke_left->currentFrame == 5)
                            {
                                smokeleft_red.erase(smokeleft_red.begin()+i);
                            }
                        }
                }
                // ................

                if(xhp_left < -360 || xhp_right > SCREEN_WIDTH)
                {
                    game_state = GAME_OVER1;
                }
                graphics.presentScene();
                SDL_Delay(12);
                break;
        }
        case GAME_LOOP:
            {
                SDL_PollEvent(&e);
                if(e.type == SDL_QUIT) quit=true;
                graphics.play(gMusic);
                background.scroll(screenscroll+more_speed_nam);
                graphics.renderbackgr(background);

                SDL_GetMouseState(&a,&b);
                if((a>SCREEN_WIDTH/2 + SCREEN_WIDTH/6&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/6+300&&b>20&&b<67)&&e.type==SDL_MOUSEBUTTONUP)
                {
                    graphics.play(gPress);
                    pausing = true;

                    while(pausing)
                    {
                        SDL_Event eve;
                        SDL_PollEvent(&eve);
                        if((a>SCREEN_WIDTH/2 + SCREEN_WIDTH/6&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/6+300&&b>20&&b<67)&&eve.type==SDL_MOUSEBUTTONUP)
                        {
                            graphics.play(gPress);
                            pausing = false;
                        }
                    }

                }
                if(pausesound)
                {
                    Mix_VolumeMusic(0);
                    Mix_VolumeChunk(gattack,0);
                    Mix_VolumeChunk(gPress,0);
                    Mix_VolumeChunk(gJump,0);
                }
                else{
                    Mix_VolumeMusic(SDL_MIX_MAXVOLUME);
                    Mix_VolumeChunk(gattack,SDL_MIX_MAXVOLUME);
                    Mix_VolumeChunk(gPress,SDL_MIX_MAXVOLUME);
                    Mix_VolumeChunk(gJump,SDL_MIX_MAXVOLUME/6);
                }
                if(!pausesound&&(a>SCREEN_WIDTH/2 + SCREEN_WIDTH/3&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/3+100&&b>100&&b<176)&&e.type == SDL_MOUSEBUTTONDOWN)
                {
                    pausesound=true;
                }
                else if(pausesound&&(a>SCREEN_WIDTH/2 + SCREEN_WIDTH/3&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/3+100&&b>100&&b<176)&&e.type == SDL_MOUSEBUTTONDOWN)
                {
                    pausesound = false;
                }
                if(!pausesound)
                {
                    graphics.renderTexture(sound_on,SCREEN_WIDTH/2 + SCREEN_WIDTH/3,100);
                }
                else if(pausesound)
                {
                    graphics.renderTexture(sound_off,SCREEN_WIDTH/2 + SCREEN_WIDTH/3,100);
                }
                graphics.renderTexture(pause,SCREEN_WIDTH/2 + SCREEN_WIDTH/6,20);


               if (diem!=0 && diem%2==0 && !screenscrollIncreased && diem<30) {

                    more_speed_nam += MORE_SPEED_NAM;
                    more_speed_redbird +=MORE_SPEED_RED_BIRD;
                    more_speed_bluebird +=MORE_SPEED_BLUE_BIRD;
                    more_speed_run+= MORE_SPEED_RUN;
                    more_speed_fatbirdx += MORE_SPEED_FATBIRD;
                    more_speed_fatbirdy += MORE_SPEED_FAT_BIRDY;
                    screenscrollIncreased = true;
                }
                if(diem%2!=0) screenscrollIncreased = false;


                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

                if((currentKeyStates[SDL_SCANCODE_UP]||currentKeyStates[SDL_SCANCODE_SPACE]||currentKeyStates[SDL_SCANCODE_W])&&checkOnGround(hero.y))
                {
                    graphics.play(gJump);
                }

                if(!nam1.is_live)
                {
                    Sprite* explosion = new Sprite;
                    SDL_Texture* explosionTexture = graphics.loadTexture(EXPLOSION_FILE);
                    explosion->init(explosionTexture, EXPLOSION_FRAMES, EXPLOSION_CLIPS);
                    explosion->x=nam1.x;
                    explosion->y=nam1.y;
                    explosion->currentFrame=0;

                    vunolon.push_back(explosion);
                }

                if( nam1.is_live == false)
                {
                    nam1.is_live = true;
                    nam1.x+= SCREEN_WIDTH;
                }

                if(!nam2.is_live)
                {
                    Sprite* explosion = new Sprite;
                    SDL_Texture* explosionTexture = graphics.loadTexture(EXPLOSION_FILE);
                    explosion->init(explosionTexture, EXPLOSION_FRAMES, EXPLOSION_CLIPS);
                    explosion->x=nam2.x;
                    explosion->y=nam2.y;
                    explosion->currentFrame=0;
                    vunolon.push_back(explosion);
                }

                if( nam2.is_live == false)
                {
                    nam2.is_live = true;
                    nam2.x+= SCREEN_WIDTH;
                }

                if(!redbird.is_live)
                {
                    Sprite* explosion = new Sprite;
                    SDL_Texture* explosionTexture = graphics.loadTexture(EXPLOSION_FILE);
                    explosion->init(explosionTexture, EXPLOSION_FRAMES, EXPLOSION_CLIPS);
                    explosion->x=redbird.x;
                    explosion->y=redbird.y;
                    explosion->currentFrame=0;
                    vunolon.push_back(explosion);
                }

                if( redbird.is_live == false)
                {
                    redbird.is_live = true;
                    redbird.x+= SCREEN_WIDTH;
                }

                if(!bluebird.is_live)
                {
                    Sprite* explosion = new Sprite;
                    SDL_Texture* explosionTexture = graphics.loadTexture(EXPLOSION_FILE);
                    explosion->init(explosionTexture, EXPLOSION_FRAMES, EXPLOSION_CLIPS);
                    explosion->x=bluebird.x;
                    explosion->y=bluebird.y;
                    explosion->currentFrame=0;
                    vunolon.push_back(explosion);
                }

                if( bluebird.is_live == false)
                {
                    bluebird.is_live = true;
                    bluebird.x+= SCREEN_WIDTH;
                }

                if(!fatbird.is_live)
                {
                    Sprite* explosion = new Sprite;
                    SDL_Texture* explosionTexture = graphics.loadTexture(EXPLOSION_FILE);
                    explosion->init(explosionTexture, EXPLOSION_FRAMES, EXPLOSION_CLIPS);
                    explosion->x=fatbird.x;
                    explosion->y=fatbird.y;
                    explosion->currentFrame=0;
                    vunolon.push_back(explosion);
                }

                if( fatbird.is_live == false)
                {
                    fatbird.is_live = true;
                    fatbird.x=-(SCREEN_HEIGHT+chieucao_fatbird);
                }

                for(int i=0 ; i<vunolon.size() ;i++)
                {
                        Sprite* explosion = vunolon[i];
                        if(explosion!=nullptr)
                        {
                            explosion->tick();
                            graphics.render(explosion->x,explosion->y,*explosion);
                            if(explosion->currentFrame == 5)
                            {
                                vunolon.erase(vunolon.begin()+i);
                            }
                        }
                }


                if(e.type == SDL_MOUSEBUTTONDOWN && !hero.click && luotchem>0 && !(a>SCREEN_WIDTH/2 + SCREEN_WIDTH/6&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/6+300&&b>20&&b<67)&&!(a>SCREEN_WIDTH/2 + SCREEN_WIDTH/3&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/3+100&&b>100&&b<176) ){
                    graphics.play(gattack);
                    luotchem--;
                    hero.click = true;
                    hero.currentFrame=0;
                    hero.attack(nam1,e);
                    hero.attack(nam2,e);
                    hero.attack(redbird,e);
                    hero.attack(bluebird,e);
                    hero.attackfat(fatbird,e);
                }

                if(hero.click)
                {
                    hero.init(heroattackTexture, HERO_ATTACK_FRAMES, HERO_ATTACK_CLIPS);
                }
                else if(!checkOnGround(hero.y))
                {
                    hero.init(herojumpTexture, HERO_JUMP_FRAMES, HERO_JUMP_CLIPS);
                }
                else hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);

                if(hero.click && hero.currentFrame==7) { hero.click=false; }
                hero.tick();
                graphics.DoPlayer(hero.x, hero.y, hero, currentKeyStates,more_speed_run);
                graphics.move(hero.x, hero.y, hero);

                //nam

                if(diem<=2 && !checkHD1)
                {
                    graphics.renderTexturehuongdan(huongdan1,xhuongdan1,yhuongdan1);
                }
                else if(diem>2&&diem<=6&& !checkHD2){
                    yhuongdan1-=4;
                    graphics.renderTexturehuongdan(huongdan1,xhuongdan1,yhuongdan1);
                    if(yhuongdan1==y_huongdan){
                        SDL_DestroyTexture(huongdan1);
                        checkHD1 = true;
                        soHD--;
                    }

                    graphics.renderTexturehuongdan(huongdanchimdo,xhuongdan2,yhuongdan2);

                }
                else if(diem>6&&diem<=9&& !checkHD3)
                {
                    yhuongdan2-=4;
                    graphics.renderTexturehuongdan(huongdanchimdo,xhuongdan2,yhuongdan2);
                    if(yhuongdan2==y_huongdan){
                        SDL_DestroyTexture(huongdanchimdo);
                        checkHD2=true;
                        soHD--;
                    }
                    graphics.renderTexturehuongdan(huongdanchimxanh,xhuongdan3,yhuongdan3);

                }
                else if(diem>9&&diem<=13&& !checkHD4)
                {
                    yhuongdan3-=4;
                    graphics.renderTexturehuongdan(huongdanchimxanh,xhuongdan3,yhuongdan3);
                    if(yhuongdan3==y_huongdan){
                        SDL_DestroyTexture(huongdanchimxanh);
                        checkHD3=true;
                        soHD--;
                    }

                    graphics.renderTexturehuongdan(huongdanchimbeo,xhuongdan4,yhuongdan4);
                }
                else if(diem>13 && diem <=16&& !checkHD5)
                {
                    yhuongdan4-=4;
                    graphics.renderTexturehuongdan(huongdanchimbeo,xhuongdan4,yhuongdan4);
                    if(yhuongdan4==y_huongdan){
                        SDL_DestroyTexture(huongdanchimbeo);
                        checkHD4 = true;
                        soHD--;
                    }

                    graphics.renderTexturehuongdan(huongdanattack,xhuongdan5,yhuongdan5);
                }
                else if(diem>=17) {
                    yhuongdan5-=4;
                    if(yhuongdan5==y_huongdan){
                        SDL_DestroyTexture(huongdanattack);
                        checkHD5 = true;
                        soHD--;
                    }
                }

                graphics.movenam(nam1.x, nam1.y,nam1, more_speed_nam);
                graphics.movenam(nam2.x, nam2.y,nam2, more_speed_nam);

                //bird
                if(diem>=3)
                {
                    redbird.tick();
                    graphics.movebird(redbird.x , redbird.y, redbird, more_speed_redbird);
                }

                if(diem>=6){
                    bluebird.tick();
                    graphics.movebird(bluebird.x,bluebird.y, bluebird , more_speed_bluebird);
                    graphics.trollbluebird(hero,bluebird);
                }

                if(diem>=11)
                {
                    fatbird.tick();
                    graphics.movefatbird(fatbird.x,fatbird.y,fatbird,more_speed_fatbirdx, more_speed_fatbirdy ,hero);
                }

                if(graphics.gameOverBirdrun(hero.x, hero.y, redbird.x, redbird.y)||graphics.gameOverBirdrun(hero.x, hero.y, bluebird.x, bluebird.y)||graphics.gameOverFatBirdrun(hero.x,hero.y,fatbird.x,fatbird.y)|| graphics.gameOvernamrun(hero.x, hero.y, nam1.x, nam1.y) || graphics.gameOvernamrun(hero.x, hero.y, nam2.x, nam2.y)||graphics.gameOverBirdjump(hero.x, hero.y, redbird.x, redbird.y)||graphics.gameOverBirdjump(hero.x, hero.y, bluebird.x, bluebird.y)||graphics.gameOverFatBirdjump(hero.x,hero.y,fatbird.x,fatbird.y)|| graphics.gameOvernamjump(hero.x, hero.y, nam1.x, nam1.y) || graphics.gameOvernamjump(hero.x, hero.y, nam2.x, nam2.y))
                {
                    somang--;
                    if(somang>=1)
                    {
                        hero.y=0;
                    }
                    if(somang<1)
                    {
                        game_state = GAME_OVER;
                    }
                }

                if(hero.checkpoint(hero.x, nam1.x) && !nam1.checkpoint_){
                    diem++;
                    luotchem++;
                    nam1.checkpoint_ = true;
                }

                if(hero.checkpoint(hero.x, nam2.x) && !nam2.checkpoint_){
                    diem++;
                    luotchem++;
                    nam2.checkpoint_ = true;
                }

                if(somang==3){
                    graphics.renderTexture(heart,kcheart, 0);
                    graphics.renderTexture(heart,kcheart2, 0);
                    graphics.renderTexture(heart,kcheart3, 0);
                }
                else if(somang==2)
                {
                    graphics.renderTexture(heart,kcheart, 0);
                    graphics.renderTexture(heart,kcheart2, 0);
                }
                else if(somang==1){
                    graphics.renderTexture(heart,kcheart, 0);
                }


                string str_number_game_loop = to_string(diem);
                string luotchem_number = to_string(luotchem);

                const char* char_number_game_loop = str_number_game_loop.c_str();
                SDL_Texture* diemtext_gameloop = graphics.renderText(char_number_game_loop, font, color);
                graphics.renderTexture(diemtext_gameloop, 480, 0);

                const char* char_luotchem_number = ("Luot chem " + luotchem_number).c_str();
                SDL_Texture* luotchemtext = graphics.renderText(char_luotchem_number, font, color);
                graphics.renderTexture(luotchemtext, 0, 60);

                SDL_Texture* heart_Text = graphics.renderText("So mang", font, color);
                graphics.renderTexture(heart_Text, 0, 0);

                SDL_DestroyTexture(diemtext_gameloop);
                SDL_DestroyTexture(luotchemtext);
                SDL_DestroyTexture(heart_Text);


                graphics.presentScene();
                SDL_Delay(10);
                break;
            }

        case GAME_OVER1:
            {
                    Mix_HaltMusic();
                    graphics.renderbackgr(background);
                    if(e.type == SDL_QUIT) quit=true;
                    if(xhp_left < -360)
                    {
                        graphics.renderTexture(player2win, SCREEN_WIDTH/2 - 100,SCREEN_HEIGHT/2.5 );
                        hero_red.init(hero_redstandTexture, HERO_RED_STAND_FRAMES, HERO_RED_STAND_CLIPS);
                        hero_red.tick();
                        graphics.render(hero_red.x,hero_red.y,hero_red);
                        if (current_frame_dead < HERO_DEAD_FRAMES) { // Kiểm tra xem có còn frame để render không
                        hero.init(heroDeadTexture, 1, &HERO_DEAD_CLIPS[current_frame_dead]);
                        current_frame_dead++; // Chuyển sang frame tiếp theo
                        }
                        hero.tick();
                        graphics.die(hero.x, hero.y, hero);
                    }
                    else if(xhp_right > SCREEN_WIDTH)
                    {
                        graphics.renderTexture(player1win, SCREEN_WIDTH/2 - 100,SCREEN_HEIGHT/2.5 );
                        hero.init(herostandTexture, HERO_STAND_FRAMES, HERO_STAND_CLIPS);
                        hero.tick();
                        graphics.render(hero.x,hero.y,hero);
                        if (current_frame_dead < HERO_RED_DEAD_FRAMES) { // Kiểm tra xem có còn frame để render không
                        hero_red.init(hero_redDeadTexture, 1, &HERO_RED_DEAD_CLIPS[current_frame_dead]);
                        current_frame_dead++; // Chuyển sang frame tiếp theo
                        }
                        hero_red.tick();
                        graphics.die(hero_red.x, hero_red.y, hero_red);
                    }

                    SDL_GetMouseState(&a,&b);
                    while( SDL_PollEvent( &e ) != 0 ) {
                    if( e.type == SDL_MOUSEBUTTONDOWN && a>SCREEN_WIDTH/4+78&&a<SCREEN_WIDTH/4+78+150&&b>350&&b<350+44 )
                    {
                        graphics.play(gPress);
                        hero.x = 5;
                        hero.y = 5;
                        nam1.x = SCREEN_WIDTH;
                        nam1.y = 370;
                        nam2.x = SCREEN_WIDTH + SCREEN_WIDTH/2;
                        nam2.y = 370;
                        redbird.x = nam1.x + SCREEN_WIDTH/3;
                        redbird.y = SCREEN_HEIGHT/2;
                        bluebird.x = nam2.x + SCREEN_WIDTH/3;
                        bluebird.y = SCREEN_HEIGHT/2;
                        fatbird.x=SCREEN_WIDTH/2.5;
                        fatbird.y=-48;
                        luotchem=0;
                        diem=0;
                        somang=3;

                        xhuongdan1=-400;
                        yhuongdan1=80;
                        xhuongdan2=-400;
                        yhuongdan2=80;
                        xhuongdan3=-400;
                        yhuongdan3=80;
                        xhuongdan4=-400;
                        yhuongdan4=80;
                        xhuongdan5=-400;
                        yhuongdan5=80;

                        more_speed_redbird=0;
                        more_speed_bluebird=0;
                        more_speed_nam=0;
                        more_speed_run=0;
                        more_speed_fatbirdx=0;
                        more_speed_fatbirdy=0;
                        current_frame_dead = 0;

                        nam1.checkpoint_ = false;
                        nam2.checkpoint_ = false;

                        xhp_left = 0;
                        xhp_right = SCREEN_WIDTH - 360;
                        xenergy = -300;
                        xenergy_red = SCREEN_WIDTH;
                        hero_red.x = 950;
                        hero_red.y = 5;

                        game_state = GAME_START;
                    }
                    else if(e.type == SDL_QUIT||(e.type == SDL_MOUSEBUTTONDOWN&&a>SCREEN_WIDTH/4+260&&a<SCREEN_WIDTH/4+410&&b>350&&b<350+44))
                    {
                        graphics.play(gPress);
                        quit=true;
                    }
                }


                if(a>SCREEN_WIDTH/4+78&&a<SCREEN_WIDTH/4+78+150&&b>350&&b<350+44)
                {
                    graphics.renderTexture(restartwhite,SCREEN_WIDTH/4+78,350);
                }
                else graphics.renderTexture(restartblack,SCREEN_WIDTH/4+78,350);

                if(a>SCREEN_WIDTH/4+260&&a<SCREEN_WIDTH/4+410&&b>350&&b<350+44)
                {
                    graphics.renderTexture(quitwhite,SCREEN_WIDTH/SCREEN_WIDTH/4+500,350);
                }
                else graphics.renderTexture(quitblack,SCREEN_WIDTH/SCREEN_WIDTH/4+500,350);

                graphics.presentScene();
                SDL_Delay(70);
                break;
            }

        case GAME_OVER:
            {
                    Mix_HaltMusic();
                    graphics.renderbackgr(background);
                    if(e.type == SDL_QUIT) quit=true;
                    if (current_frame_dead < HERO_DEAD_FRAMES) { // Kiểm tra xem có còn frame để render không
                        hero.init(heroDeadTexture, 1, &HERO_DEAD_CLIPS[current_frame_dead]);
                        current_frame_dead++; // Chuyển sang frame tiếp theo
                    }
                    hero.tick();
                    graphics.die(hero.x, hero.y, hero);

                    SDL_GetMouseState(&a,&b);
                    while( SDL_PollEvent( &e ) != 0 ) {
                    if( e.type == SDL_MOUSEBUTTONDOWN && a>SCREEN_WIDTH/4+78&&a<SCREEN_WIDTH/4+78+150&&b>350&&b<350+44 )
                    {
                        graphics.play(gPress);
                        hero.x = 5;
                        hero.y = 5;
                        nam1.x = SCREEN_WIDTH;
                        nam1.y = 370;
                        nam2.x = SCREEN_WIDTH + SCREEN_WIDTH/2;
                        nam2.y = 370;
                        redbird.x = nam1.x + SCREEN_WIDTH/3;
                        redbird.y = SCREEN_HEIGHT/2;
                        bluebird.x = nam2.x + SCREEN_WIDTH/3;
                        bluebird.y = SCREEN_HEIGHT/2;
                        fatbird.x=SCREEN_WIDTH/2.5;
                        fatbird.y=-48;
                        luotchem=0;
                        diem=0;
                        somang=3;

                        xhuongdan1=-400;
                        yhuongdan1=80;
                        xhuongdan2=-400;
                        yhuongdan2=80;
                        xhuongdan3=-400;
                        yhuongdan3=80;
                        xhuongdan4=-400;
                        yhuongdan4=80;
                        xhuongdan5=-400;
                        yhuongdan5=80;

                        more_speed_redbird=0;
                        more_speed_bluebird=0;
                        more_speed_nam=0;
                        more_speed_run=0;
                        more_speed_fatbirdx=0;
                        more_speed_fatbirdy=0;
                        current_frame_dead = 0;

                        nam1.checkpoint_ = false;
                        nam2.checkpoint_ = false;

                        game_state = GAME_START;
                    }
                    else if(e.type == SDL_QUIT||(e.type == SDL_MOUSEBUTTONDOWN&&a>SCREEN_WIDTH/4+260&&a<SCREEN_WIDTH/4+410&&b>350&&b<350+44))
                    {
                        graphics.play(gPress);
                        quit=true;
                    }
                }

                graphics.renderbackgr(background);

                if (current_frame_dead < HERO_DEAD_FRAMES) {
                    hero.init(heroDeadTexture, 1, &HERO_DEAD_CLIPS[current_frame_dead]);
                    current_frame_dead++;
                }
                hero.tick();
                graphics.die(hero.x, hero.y, hero);

                graphics.renderTexture(treeTexture, nam1.x , nam1.y);
                graphics.renderTexture(treeTexture2, nam2.x , nam2.y);

                redbird.tick();
                graphics.renderbird(redbird.x , redbird.y, redbird);

                bluebird.tick();
                graphics.renderbird(bluebird.x , bluebird.y, bluebird);

                fatbird.tick();
                graphics.renderbird(fatbird.x , fatbird.y, fatbird);

                graphics.renderTexture(gameover,SCREEN_WIDTH/4,SCREEN_HEIGHT/6);
                if(a>SCREEN_WIDTH/4+78&&a<SCREEN_WIDTH/4+78+150&&b>350&&b<350+44)
                {
                    graphics.renderTexture(restartwhite,SCREEN_WIDTH/4+78,350);
                }
                else graphics.renderTexture(restartblack,SCREEN_WIDTH/4+78,350);

                if(a>SCREEN_WIDTH/4+260&&a<SCREEN_WIDTH/4+410&&b>350&&b<350+44)
                {
                    graphics.renderTexture(quitwhite,SCREEN_WIDTH/SCREEN_WIDTH/4+500,350);
                }
                else graphics.renderTexture(quitblack,SCREEN_WIDTH/SCREEN_WIDTH/4+500,350);

                string str_number = to_string(diem);
                const char* char_number =("Diem so: " + str_number).c_str();
                SDL_Texture* diemtext = graphics.renderText(char_number, font, color);
                graphics.renderTexture(diemtext, 20, SCREEN_HEIGHT/3);

                int highscore;
                ifstream file("D:\LTNC\BAITAPLON_GAME_RUNTODIE_HOANTHANH-COPY\MAXSCORE.text");
                file>>highscore;
                file.close();

                highscore = max(highscore, diem);

                ofstream myfile("D:\LTNC\BAITAPLON_GAME_RUNTODIE_HOANTHANH-COPY\MAXSCORE.text");
                myfile<<highscore;
                myfile.close();

                string highscore_number = to_string(highscore);
                const char* char_highscore_number =("Ky luc: " + highscore_number).c_str();
                SDL_Texture* highscore_text = graphics.renderText(char_highscore_number, font, color);
                graphics.renderTexture(highscore_text, 20, SCREEN_HEIGHT/2);


                SDL_DestroyTexture(highscore_text);
                SDL_DestroyTexture(diemtext);

                graphics.presentScene();
                SDL_Delay(70);
                break;
            }
        }
    }
    SDL_DestroyTexture( heroTexture ); heroTexture = nullptr;
    if (gJump != nullptr) Mix_FreeChunk( gJump);
    SDL_DestroyTexture (heroDeadTexture); heroDeadTexture = nullptr;
    SDL_DestroyTexture (heroattackTexture); heroattackTexture = nullptr;
    SDL_DestroyTexture( herojumpTexture ); herojumpTexture = nullptr;
    SDL_DestroyTexture( bluebirdTexture ); bluebirdTexture = nullptr;
    SDL_DestroyTexture( redbirdTexture ); redbirdTexture = nullptr;
    SDL_DestroyTexture( fatbirdTexture ); fatbirdTexture = nullptr;

    SDL_DestroyTexture( background.texture );
    graphics.quit();
    return 0;
}
