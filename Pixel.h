#ifndef PIXEL_H
#define PIXEL_H
#include"Color.h"

#include <iostream>
using namespace std;

class Pixel
{
  private:
    int _x;
    int _y;
    Color _col;

  public:
    Pixel();
    Pixel(int x, int y, Color col);
    Pixel(Pixel const &pix);
    friend ostream & operator << (ostream &op, Pixel &pix);
    void set_p(float r, float g, float b);
    int get_x();
    int get_y();
    friend Pixel& operator+(Pixel pixel1, Pixel pixel2);
    friend Pixel& operator*(float f, Pixel pixel2);
    Color& get_cr();
    Pixel& operator=(Pixel const &other);
    Color get_c();
};
#endif
