#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include "Color.h"
#include "Pixel.h"

class Image {
protected:
  int _w,_h;
  Pixel **_p;
public:
  Image();
  Image(int w,int h);
  Image(Image &i);
  friend ostream & operator << (ostream &out, Image &i);
  Pixel get_p(int x,int y);
  Pixel& get_pr(int x,int y);
  void set_p(Pixel p,int x,int y);
  int get_w();
  int get_h();
  Image& operator=(Image const &other);
  // friend Image& operator+(Image &image1, Image &image2);
  // friend Image& operator*(float f, Image &image);
};

#endif
