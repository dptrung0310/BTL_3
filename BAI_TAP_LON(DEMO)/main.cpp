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
bool checkdiem(int diem)
{
    if(diem==5 || diem==10 || diem==15 || diem==20 ) return true;
    return false;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Graphics graphics;
    graphics.init();

    Mix_Chunk *gJump = graphics.loadSound("assets\\jump.wav");

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));

    Sprite hero;
    SDL_Texture* heroTexture = graphics.loadTexture(HERO);
    //hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);

    SDL_Texture* herojumpTexture=graphics.loadTexture(HERO_JUMP);
    SDL_Texture* heroDeadTexture=graphics.loadTexture(HERO_DEAD);

    SDL_Texture* buttonplaywhite=graphics.loadTexture("img\\Playnowwhite.png");
    SDL_Texture* buttonplayblack=graphics.loadTexture("img\\Playnowblack.png");

    bool start=false;
    SDL_Event event;

    while(!start){
        int a,b;
        SDL_GetMouseState(&a,&b);
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_MOUSEBUTTONDOWN && (a>320&&a<620&&b>320&&b<387))
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
        TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",70 );
        SDL_Color color = {255, 255, 0, 0};
        SDL_Texture* helloText = graphics.renderText("Run To Die", font, color);
        graphics.renderTexture(helloText, 315, 140);

        //hero
        hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);
        hero.tick();
        graphics.render(440,230,hero);
        graphics.presentScene();
        SDL_Delay(1);

    }



    Sprite redbird;
    SDL_Texture* redbirdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    redbird.init(redbirdTexture,BIRD_FRAMES,BIRD_CLIPS);
    /*Sprite blackbird;
    redbird2.init(redbirdTexture,BIRD_FRAMES,BIRD_CLIPS);*/


    Sprite nam1;
    Sprite nam2;
    SDL_Texture* treeTexture = graphics.loadTexture("img\\nam.png");
    SDL_Texture* treeTexture2 = graphics.loadTexture("img\\nam.png");
    nam1.init(treeTexture,NAM_FRAMES,NAM_CLIPS);
    nam2.init(treeTexture2,NAM_FRAMES,NAM_CLIPS);


    hero.x = 5;
    hero.y = 5;


    nam1.x = SCREEN_WIDTH;
    nam1.y = 370;
    nam2.x = SCREEN_WIDTH*3/2;
    nam2.y = 370;

    redbird.x = nam1.x + 60;
    redbird.y = SCREEN_HEIGHT/2;




    float screenscroll=SCREEN_SCROLL;
    float more_speed=0;

    bool quit = false;
    SDL_Event e;

    int diem=0;
    bool screenscrollIncreased = false;

    while( !quit && !graphics.gameOvernam(hero.x, hero.y, nam1.x, nam1.y) && !graphics.gameOvernam(hero.x, hero.y, nam2.x, nam2.y)) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }
        background.scroll(screenscroll+more_speed);
        graphics.renderbackgr(background);

       if (diem!=0 && diem%5==0 && !screenscrollIncreased) {
            more_speed += MORE_SPEED; // Tăng speed object lên 1
            screenscrollIncreased = true; // Đặt cờ đã tăng screenscroll
        }
        if(diem%5!=0) screenscrollIncreased = false;
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(currentKeyStates[SDL_SCANCODE_UP]&&checkOnGround(hero.y))
        {
            graphics.play(gJump);
        }

        if(!checkOnGround(hero.y))
        {
            hero.init(herojumpTexture, HERO_JUMP_FRAMES, HERO_JUMP_CLIPS);
        }
        else{
            hero.init(heroTexture, HERO_FRAMES, HERO_CLIPS);
        }

        hero.tick();
        graphics.DoPlayer(hero.x, hero.y, hero, currentKeyStates);
        graphics.move(hero.x, hero.y, hero);
        //nam

        nam1.tick();
        nam2.tick();
        graphics.movenam(nam1.x, nam1.y,nam1, more_speed);
        graphics.movenam(nam2.x, nam2.y,nam2, more_speed);

        //bird
        if(diem>=5)
        {
            redbird.tick();
            graphics.movebird(redbird.x , redbird.y, redbird, more_speed);
        }
        else if(diem>=8)
        {
            graphics.trollblackbird(hero,redbird);
        }
        graphics.trollblackbird(hero,redbird);

        if(graphics.gameOverBird(hero.x, hero.y, redbird.x, redbird.y))
        {
            quit=true;
        }
        if(hero.checkpoint(hero.x, nam1.x) && !nam1.checkpoint_){
            diem++;
            nam1.checkpoint_ = true;
        }
        if(hero.checkpoint(hero.x, nam2.x) && !nam2.checkpoint_){
            diem++;
            nam2.checkpoint_ = true;
        }

        TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",40 );
        SDL_Color color = {255, 255, 0, 0};
        string str_number = to_string(diem);
        const char* char_number = str_number.c_str();
        SDL_Texture* diemtext = graphics.renderText(char_number, font, color);
        graphics.renderTexture(diemtext, 480, 0);

        graphics.presentScene();
        SDL_Delay(15);
    }
    SDL_DestroyTexture( heroTexture ); heroTexture = nullptr;
    if (gJump != nullptr) Mix_FreeChunk( gJump);

    bool quitout = false;
    bool game_over_rendered = false;
    int current_frame = 0;
    SDL_Event eout;

    while( !quitout ){
        graphics.renderbackgr(background);

        if (current_frame < HERO_DEAD_FRAMES) { // Kiểm tra xem có còn frame để render không
            hero.init(heroDeadTexture, 1, &HERO_DEAD_CLIPS[current_frame]);
            current_frame++; // Chuyển sang frame tiếp theo
        }
        hero.tick();
        graphics.move(hero.x, hero.y, hero);

        graphics.renderTexture(treeTexture, nam1.x , nam1.y);
        graphics.renderTexture(treeTexture2, nam2.x , nam2.y);
        redbird.init(redbirdTexture,BIRD_FRAMES,BIRD_CLIPS);
        redbird.tick();

        graphics.renderbird(redbird.x , redbird.y, redbird);
        graphics.presentScene();
        SDL_Delay(25);
    }
    SDL_DestroyTexture( herojumpTexture ); herojumpTexture = nullptr;
    SDL_DestroyTexture( background.texture );
    graphics.quit();
    return 0;
}
