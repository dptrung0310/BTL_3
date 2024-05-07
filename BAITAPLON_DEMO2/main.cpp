#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"


using namespace std;



bool checkOnGround(int y){
    if(y==340) return true;
    return false;
}


int main(int argc, char *argv[])
{

    srand(time(NULL));
    Graphics graphics;
    graphics.init();
    tryAgain: // nhãn

    Mix_Music *gMusic = graphics.loadMusic("assets\\tiengtrongtudo.mp3");
    graphics.play(gMusic);
    Mix_Chunk *gJump = graphics.loadSound("assets\\7M5K8H4-wizard-jumping-jump.wav");
    Mix_Chunk *gattack=graphics.loadSound("assets\\L8SWRY6-sword-attack.wav");

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));

    Sprite hero;
    SDL_Texture* heroTexture = graphics.loadTexture(HERO);
    hero.x = 5;
    hero.y = 5;

    SDL_Texture* herojumpTexture=graphics.loadTexture(HERO_JUMP);
    SDL_Texture* heroDeadTexture=graphics.loadTexture(HERO_DEAD);
    SDL_Texture* heroattackTexture=graphics.loadTexture(HERO_ATTACK);

    SDL_Texture* buttonplaywhite=graphics.loadTexture("img\\Playnowwhite.png");
    SDL_Texture* buttonplayblack=graphics.loadTexture("img\\Playnowblack.png");
    SDL_Texture* titlegame=graphics.loadTexture("img\\titlegame.png");
    SDL_Texture* signgame=graphics.loadTexture("img\\signed.png");

    bool start=false;
    SDL_Event event;

    while(!start){
        int a,b;
        SDL_GetMouseState(&a,&b);
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT||(event.type==SDL_MOUSEBUTTONDOWN && (a>320&&a<620&&b>320&&b<387)))
            {
                start=true;
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
        TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",70 );
        SDL_Color color = {255, 239, 63, 0};
        SDL_Color color2 = {0, 0, 0, 0};
        SDL_Texture* helloText = graphics.renderText("Run To Die", font, color);
        SDL_Texture* helloText2 = graphics.renderText("Run To Die", font, color2);
        graphics.renderTexture(helloText2, 313, 142);
        graphics.renderTexture(helloText, 315, 140);


        //hero
        hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);
        hero.tick();
        graphics.render(440,230,hero);
        graphics.presentScene();
        SDL_Delay(5);

    }
    Sprite nam1;
    Sprite nam2;
    SDL_Texture* treeTexture = graphics.loadTexture("img\\nam.png");
    SDL_Texture* treeTexture2 = graphics.loadTexture("img\\nam.png");
    nam1.init(treeTexture,NAM_FRAMES,NAM_CLIPS);
    nam2.init(treeTexture2,NAM_FRAMES,NAM_CLIPS);
    nam1.x = SCREEN_WIDTH;
    nam1.y = 370;
    nam2.x = nam1.x + SCREEN_WIDTH/2;
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
    fatbird.y=0;


    float screenscroll=SCREEN_SCROLL;
    float more_speed_redbird=0;
    float more_speed_bluebird=0;
    float more_speed_nam=0;
    float more_speed_run=0;
    bool quit = false;
    SDL_Event e;

    int diem=0;
    int luotchem=0;
    bool screenscrollIncreased = false;

    while( !quit && !graphics.gameOvernam(hero.x, hero.y, nam1.x, nam1.y) && !graphics.gameOvernam(hero.x, hero.y, nam2.x, nam2.y)) {
        SDL_PollEvent(&e);
        if( e.type == SDL_QUIT ) quit = true;

        background.scroll(screenscroll+more_speed_nam);
        graphics.renderbackgr(background);

       if (diem!=0 && diem%3==0 && !screenscrollIncreased) {
            more_speed_nam += MORE_SPEED_NAM;
            more_speed_redbird +=MORE_SPEED_RED_BIRD;
            more_speed_bluebird +=MORE_SPEED_BLUE_BIRD;
            more_speed_run+= MORE_SPEED_RUN;
            screenscrollIncreased = true; // Đặt cờ đã tăng screenscroll
        }
        if(diem%3!=0) screenscrollIncreased = false;


        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if((currentKeyStates[SDL_SCANCODE_UP]||currentKeyStates[SDL_SCANCODE_SPACE]||currentKeyStates[SDL_SCANCODE_W])&&checkOnGround(hero.y))
        {
            graphics.play(gJump);
        }

        if(e.type==SDL_MOUSEBUTTONDOWN && !hero.click && luotchem>0){
            graphics.play(gattack);
            hero.click = true;
            hero.currentFrame=0;
            hero.attack(nam1,e);
            hero.attack(nam2,e);
            hero.attack(redbird,e);
            hero.attack(bluebird,e);
            hero.attackfat(fatbird,e);
        }

        if(hero.click && hero.currentFrame==7) { luotchem--; hero.click=false; }
        if(hero.click) hero.init(heroattackTexture, HERO_ATTACK_FRAMES, HERO_ATTACK_CLIPS);
        else if(!checkOnGround(hero.y))
        {
            hero.init(herojumpTexture, HERO_JUMP_FRAMES, HERO_JUMP_CLIPS);
        }
        else hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);

        hero.tick();
        graphics.DoPlayer(hero.x, hero.y, hero, currentKeyStates,more_speed_run);
        graphics.move(hero.x, hero.y, hero);
        //nam

        nam1.tick();
        nam2.tick();
        graphics.movenam(nam1.x, nam1.y,nam1, more_speed_nam);
        graphics.movenam(nam2.x, nam2.y,nam2, more_speed_nam);

        //bird
        if(diem>=2)
        {
            redbird.tick();
            graphics.movebird(redbird.x , redbird.y, redbird, more_speed_redbird);
        }

        if(diem>=5){
            bluebird.tick();
            graphics.movebird(bluebird.x,bluebird.y, bluebird , more_speed_bluebird);
            graphics.trollbluebird(hero,bluebird);
        }

        if(diem>=10)
        {
            fatbird.tick();
            graphics.movefatbird(fatbird.x,fatbird.y,fatbird,more_speed_bluebird,hero);
        }

        if(graphics.gameOverBird(hero.x, hero.y, redbird.x, redbird.y)||graphics.gameOverBird(hero.x, hero.y, bluebird.x, bluebird.y)||graphics.gameOverFatBird(hero.x,hero.y,fatbird.x,fatbird.y))
        {
            quit=true;
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

        TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",40 );
        SDL_Color color = {255, 255, 0, 0};
        string str_number = to_string(diem);
        const char* char_number = str_number.c_str();
        SDL_Texture* diemtext = graphics.renderText(char_number, font, color);
        graphics.renderTexture(diemtext, 480, 0);

        graphics.presentScene();
        SDL_Delay(13);
    }
    SDL_DestroyTexture( heroTexture ); heroTexture = nullptr;
    if (gJump != nullptr) Mix_FreeChunk( gJump);

    bool quitout = false;
    bool game_over_rendered = false;
    int current_frame = 0;
    SDL_Event eout;

    SDL_Texture* gameover = graphics.loadTexture("img\\gameover.png");
    SDL_Texture* restartwhite= graphics.loadTexture("img\\restartwhite.png");
    SDL_Texture* restartblack= graphics.loadTexture("img\\restartblack.png");

    Mix_HaltMusic();


    while( !quitout ){
        int a,b;
        SDL_GetMouseState(&a,&b);
        while( SDL_PollEvent( &eout ) != 0 ) {
            if( eout.type == SDL_MOUSEBUTTONDOWN && a>SCREEN_WIDTH/4+78&&a<SCREEN_WIDTH/4+78+150&&b>350&&b<350+44 )
            {
            goto tryAgain;
            }
            else if(eout.type == SDL_QUIT)
            {
                quitout=true;
            }
        }
        graphics.renderbackgr(background);

        if (current_frame < HERO_DEAD_FRAMES) { // Kiểm tra xem có còn frame để render không
            hero.init(heroDeadTexture, 1, &HERO_DEAD_CLIPS[current_frame]);
            current_frame++; // Chuyển sang frame tiếp theo
        }
        hero.tick();
        graphics.die(hero.x, hero.y, hero);

        graphics.renderTexture(treeTexture, nam1.x , nam1.y);
        graphics.renderTexture(treeTexture2, nam2.x , nam2.y);
        redbird.init(redbirdTexture,BIRD_FRAMES,BIRD_CLIPS);
        redbird.tick();
        graphics.renderbird(redbird.x , redbird.y, redbird);

        bluebird.init(bluebirdTexture,BLUE_BIRD_FRAMES,BLUE_BIRD_CLIPS);
        bluebird.tick();
        graphics.renderbird(bluebird.x , bluebird.y, bluebird);
        if(diem>=10)
        {
            fatbird.init(fatbirdTexture,FAT_BIRD_FRAMES,FAT_BIRD_CLIPS);
            fatbird.tick();
            graphics.renderbird(fatbird.x , fatbird.y, fatbird);
        }

        graphics.renderTexture(gameover,SCREEN_WIDTH/4,SCREEN_HEIGHT/6);
        if(a>SCREEN_WIDTH/4+78&&a<SCREEN_WIDTH/4+78+150&&b>350&&b<350+44)
        {
            graphics.renderTexture(restartwhite,SCREEN_WIDTH/4+78,350);
        }
        else graphics.renderTexture(restartblack,SCREEN_WIDTH/4+78,350);

        TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",40 );
        SDL_Color color = {255, 255, 0, 0};
        string str_number = to_string(diem);
        const char* char_number = str_number.c_str();
        SDL_Texture* diemtext = graphics.renderText(char_number, font, color);
        graphics.renderTexture(diemtext, 480, 0);

        graphics.presentScene();
        SDL_Delay(25);
    }
    SDL_DestroyTexture( herojumpTexture ); herojumpTexture = nullptr;
    SDL_DestroyTexture( background.texture );
    graphics.quit();
    return 0;
}
