#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED

#include "CommonFunc.h"
using namespace std;
class BaseObject{
public:
  BaseObject();
  ~BaseObject();
  virtual bool LoadImg(string path, SDL_Renderer* screen);
  void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);

  void Free();
  void SetRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;};
  SDL_Rect GetRect() const {return rect_;}
  SDL_Texture* GetObject() {return p_object_;}

  void setColor(const Uint8& red, const Uint8& green, const Uint8& blue);
  void setAlpha(const Uint8& alpha);
  void setBlendMode(const SDL_BlendMode& blending);

protected:
  SDL_Texture* p_object_;
  SDL_Rect rect_;
};

#endif // BASEOBJECT_H_INCLUDED
