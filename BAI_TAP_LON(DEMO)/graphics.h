#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include <vector>
#include<SDL_ttf.h>
#include <SDL_mixer.h>
#include<bits/stdc++.h>

using namespace std;

struct ScrollingBackground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;

    void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }
};


struct Sprite {
    float x=0;
    float y=0;
    bool checkpoint_ = false;
    int currentFrame = 0;
    int framecount = 0;
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        clips.clear();
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick() {
        framecount = (framecount+1)%4;
        if (framecount == 0) {
            currentFrame = (currentFrame + 1) % clips.size();
        }
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
    bool checkpoint(const int& xp, const int& xb){
        if(xp>xb){
            return true;
        }
        return false;
    }
};






struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;
	float x_val=0;
	float y_val=0;

	void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

	void init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (TTF_Init() == -1) {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
        }

        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
    }

	void prepareScene(SDL_Texture * background = nullptr)
    {
        SDL_RenderClear(renderer);
        if (background != nullptr) SDL_RenderCopy( renderer, background, NULL, NULL);
    }

    void presentScene()
    {
        SDL_RenderPresent(renderer);
    }

    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

    void renderTexture(SDL_Texture *texture, float x, float y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    void blitRect(SDL_Texture *texture, SDL_Rect *src, float x, float y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = src->w;
        dest.h = src->h;

        SDL_RenderCopy(renderer, texture, src, &dest);
    }

    void quit()
    {
        TTF_Quit();
        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void renderbackgr(const ScrollingBackground& background) {

        renderTexture(background.texture, background.scrollingOffset, 0);
        renderTexture(background.texture, background.scrollingOffset - background.width, 0);
    }

    void render(float x, float y, Sprite& sprite) {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }
    void renderbird(float x, float y, Sprite& sprite) {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }
    void DoPlayer(float &x, float &y ,const Sprite& sprite, const Uint8* currentKeyStates){
        x_val=0;
        y_val+= SPEED_FALL;
        if(y_val >= MAX_FALL_SPEED) y_val = MAX_FALL_SPEED;
        if((currentKeyStates[SDL_SCANCODE_UP]||currentKeyStates[SDL_SCANCODE_W]) && y==340)
        {
            y_val = -jump;
        }
        if((currentKeyStates[SDL_SCANCODE_SPACE]||currentKeyStates[SDL_SCANCODE_W]) && y==340)
        {
            y_val = -(jump-jump/4);
        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT]||currentKeyStates[SDL_SCANCODE_D])
        {
            x_val+=speed_run;
        }
        if(currentKeyStates[SDL_SCANCODE_LEFT]||currentKeyStates[SDL_SCANCODE_A])
        {
            x_val-=speed_run;
        }
    }

    void move(float &x, float &y ,const Sprite& sprite)
    {
        x+=x_val;
        y+=y_val;
        if (x < 0) {
            x = 0; // Đảm bảo không vượt quá biên trái
        }
        if (y < 0) {
            y = 0; // Đảm bảo không vượt quá biên trên
        }
        if (x + 80 > SCREEN_WIDTH) {
            x = SCREEN_WIDTH - 80; // Đảm bảo không vượt quá biên phải
        }
        if (y + 80 >= 420) {
            y = 340; // Đảm bảo không vượt quá y=320
        }
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }

     void movebird(float &x, float &y , Sprite& sprite, float more_speed)
    {
        x -= (speed_object+more_speed);
        if(x<=0)
        {
            x=SCREEN_WIDTH;
            y=(rand()%130)+240;
        }
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }
    bool trollx(float khoangtrollx)
    {
        if(khoangtrollx<=50) return true;
        return false;
    }
    void trollblackbird(Sprite& hero, Sprite& blackbird){
        float khoangtrolly=blackbird.y-SCREEN_HEIGHT/2;
        float khoangtrollx= blackbird.x-hero.x;
        if(trollx(khoangtrollx)&&blackbird.y>SCREEN_HEIGHT/2)
        {
            blackbird.y-=khoangtrolly+10;
            cout<<"ok"<<endl;
        }
    }
    void movenam(float &x, float &y , Sprite& sprite, float more_speed)
    {
        x -= (speed_object+more_speed);
        if(x<=0)
        {
            x=SCREEN_WIDTH;
            sprite.checkpoint_ = false;
        }
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }

    void renderobject(float &x, float &y, SDL_Texture* objectTexture) {
        renderTexture(objectTexture, x, y);
    }
    void moveobject( float &x, float &y, SDL_Texture* objectTexture)
    {
        x -= speed_object;
        if(x<=0)
        {
            x=SCREEN_WIDTH;
        }
        renderobject(x,y,objectTexture);
    }

    bool gameOvernam(float &x,float &y , float &m , float &n)
    {
        float left1 = x;
        float right1 = x + 45;
        float top1 = y;
        float bottom1 = y + 55;
        float left2 = m;
        float right2 = m + 10; // Giả sử kích thước của cây là 80x80
        float top2 = n;
        float bottom2 = n + 40;

        // Kiểm tra xem có sự chồng chéo giữa hai hình chữ nhật không
        if (left1 < right2 && right1 > left2&& top1 < bottom2 && bottom1 > top2) {
            return true; // Có va chạm
        } else {
        return false; // Không có va chạm
        }
    }
    bool gameOverBird(float &x, float &y, float& x_bird, float &y_bird )
    {
        float left1 = x;
        float right1 = x + 30;
        float top1 = y;
        float bottom1 = y + 30;
        float left2 = x_bird;
        float right2 = x_bird + 30;
        float top2 = y_bird;
        float bottom2 = y_bird + 30;

        // Kiểm tra xem có sự chồng chéo giữa hai hình chữ nhật không
        if (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2) {
            return true; // Có va chạm
        } else {
        return false; // Không có va chạm
        }
    }

    //TEXT
    TTF_Font* loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
        return gFont; // Thêm dòng này để trả về gFont
    }

    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor)
    {
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;
    }
    //MUSIC
    Mix_Music *loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

    Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
        return gChunk;
    }
    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }
};

#endif // _GRAPHICS__H
