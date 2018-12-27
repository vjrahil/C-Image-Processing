#include "Color.h"
#include <cmath>
#include <iostream>

using namespace std;

Color::Color(){}

Color::Color(int r,int g,int b)
{
  _r = r;
  _g = g;
  _b = b;
}

Color::~Color(){}

Color::Color(Color const &c)
{
  _r = c._r;
  _g = c._g;
  _b = c._b;
}

ostream & operator << (ostream &op, Color &col)
{
  op<<col._r<<" "<<col._g<<" "<<col._b;
  return op;
}

istream & operator >> (istream &ip, Color &col)
{
  ip>>col._r>>col._g>>col._b;
  return ip;
}

bool Color::operator==(Color const &a)
{
  return _r == a._r && _g == a._g && _b == a._b;
}

Color& operator+ (Color c,Color t){
    Color& ans=*(new Color());
    ans.set_r(t.get_r()+c.get_r());
    ans.set_g(t.get_g()+c.get_g());
    ans.set_b(t.get_b()+c.get_b());
    if(ans.get_r()>255) ans.set_r(255);
    if(ans.get_g()>255) ans.set_g(255);
    if(ans.get_b()>255) ans.set_b(255);
    return ans;
}
Color& operator* (float x,Color c){
  Color& ans=*(new Color());
    ans.set_r(c.get_r()*x);
    ans.set_g(c.get_g()*x);
    ans.set_b(c.get_b()*x);
    if(ans.get_r()>255) ans.set_r(255);
    if(ans.get_g()>255) ans.set_g(255);
    if(ans.get_b()>255) ans.set_b(255);
    return ans;
}

void Color::set_r(int r)
{
  _r = r;
}

void Color::set_g(int g)
{
  _g = g;
}

void Color::set_b(int b)
{
  _b = b;
}

int Color::get_r()
{
  return _r;
}

int Color::get_g()
{
  return _g;
}

int Color::get_b()
{
  return _b;
}
