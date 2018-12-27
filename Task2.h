#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <vector>
#include "Color.h"
#include "Image.h"
#include "Pixel.h"
#include <fstream>
#include "CompositeImage.h"

using namespace std;
class Task2{
private:
  Image A;
public:
  Task2(Image &ori);
  Color  get_Color_x_y(Image ori,int x,int y);
  Image get_image();
  vector<Pixel> get_blue_minima();
  Image gaussian(vector<Pixel> v,Image img);
};
#endif
