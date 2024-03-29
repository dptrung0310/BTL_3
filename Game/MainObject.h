#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED

#include"CommonFunc.h"
#include"BaseObject.h"

class MainObject: public BaseObject
{
public:
    MainObject();
    ~MainObject();
    enum WalkType
    {
        WALK_RIGHT = 0,
        WALK_LEFT=1,
    };// luu hai trang thai trai hay phai
    bool LoadImg(std:: string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandelIputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clips();

private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[8]; // luu cac hoat anh cua nhan vat o day la 8 hoat dong
    Input input_type_; // luu cac nut trang thai
    int frame_; // chi so frame
    int status_;// trang thai di chuyen sang ben trai hay phai
};

#endif // MAINOBJECT_H_INCLUDED
