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

    Mix_VolumeChunk(gJump,MIX_MAX_VOLUME*0.2);
    Mix_VolumeChunk(gattack,MIX_MAX_VOLUME*0.3);
    Mix_VolumeChunk(gPress,MIX_MAX_VOLUME*0.3);

    SDL_Texture* sound_on= graphics.loadTexture("img\\sound_on.png");
    SDL_Texture* sound_off= graphics.loadTexture("img\\sound_off.png");

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

    SDL_Texture* pause = graphics.loadTexture("img\\PAUSE.png");

    TTF_Font* efont = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",70 );
    SDL_Color ecolor = {255, 239, 63, 0};
    SDL_Color ecolor2 = {0, 0, 0, 0};

    TTF_Font* font = graphics.loadFont("assets\\Paintingwithchocolate-K5mo.ttf",40 );
    SDL_Color color = {255, 255, 0, 0};

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
    fatbird.y=-48;

    float screenscroll=SCREEN_SCROLL;
    float more_speed_redbird=0;
    float more_speed_bluebird=0;
    float more_speed_nam=0;
    float more_speed_run=0;
    float more_speed_fatbirdx=0;
    float more_speed_fatbirdy=0;
    int luotchem=0;

    bool quitout = false;
    int current_frame_dead = 0;
    SDL_Event eout;

    SDL_Texture* gameover = graphics.loadTexture("img\\gameover.png");
    SDL_Texture* restartwhite= graphics.loadTexture("img\\restartwhite.png");
    SDL_Texture* restartblack= graphics.loadTexture("img\\restartblack.png");
    SDL_Texture* quitwhite= graphics.loadTexture("img\\quitwhite.png");
    SDL_Texture* quitblack= graphics.loadTexture("img\\quitblack.png");

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
                        game_state=GAME_LOOP;
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

                SDL_Texture* helloText = graphics.renderText("Run To Die", efont, ecolor);
                SDL_Texture* helloText2 = graphics.renderText("Run To Die", efont, ecolor2);
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


               if (diem!=0 && diem%2==0 && !screenscrollIncreased) {

                    more_speed_nam += MORE_SPEED_NAM;
                    more_speed_redbird +=MORE_SPEED_RED_BIRD;
                    more_speed_bluebird +=MORE_SPEED_BLUE_BIRD;
                    more_speed_run+= MORE_SPEED_RUN;
                    more_speed_fatbirdx += MORE_SPEED_FATBIRD;
                    more_speed_fatbirdy += MORE_SPEED_FAT_BIRDY;
                    screenscrollIncreased = true; // Đặt cờ đã tăng screenscroll
                }
                if(diem%2!=0) screenscrollIncreased = false;


                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

                if((currentKeyStates[SDL_SCANCODE_UP]||currentKeyStates[SDL_SCANCODE_SPACE]||currentKeyStates[SDL_SCANCODE_W])&&checkOnGround(hero.y))
                {
                    graphics.play(gJump);
                }

                if(diem>=14&&e.type==SDL_MOUSEBUTTONDOWN && !hero.click && luotchem>0 && !(a>SCREEN_WIDTH/2 + SCREEN_WIDTH/6&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/6+300&&b>20&&b<67)&&!(a>SCREEN_WIDTH/2 + SCREEN_WIDTH/3&&a<SCREEN_WIDTH/2 + SCREEN_WIDTH/3+100&&b>100&&b<176) ){
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

                if(hero.click) hero.init(heroattackTexture, HERO_ATTACK_FRAMES, HERO_ATTACK_CLIPS);
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

                graphics.presentScene();
                SDL_Delay(11);
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
                    else if(e.type == SDL_QUIT||e.type == SDL_MOUSEBUTTONDOWN&&a>SCREEN_WIDTH/4+260&&a<SCREEN_WIDTH/4+410&&b>350&&b<350+44)
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
                ifstream file("D:\LTNC\BAITAPLON_GAME_RUNTODIE_HOANTHANH\MAXSCORE.text");
                file>>highscore;
                file.close();

                highscore = max(highscore, diem);

                ofstream myfile("D:\LTNC\BAITAPLON_GAME_RUNTODIE_HOANTHANH\MAXSCORE.text");
                myfile<<highscore;
                myfile.close();

                string highscore_number = to_string(highscore);
                const char* char_highscore_number =("Ky luc: " + highscore_number).c_str();
                SDL_Texture* highscore_text = graphics.renderText(char_highscore_number, font, color);
                graphics.renderTexture(highscore_text, 20, SCREEN_HEIGHT/2);


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
    SDL_DestroyTexture( background.texture );
    graphics.quit();
    return 0;
}
