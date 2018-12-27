#ifndef REFLECTION_H
#define REFLECTION_H
#include "Image.h"
#include<iostream>

using namespace std;

class Reflection : public Image{
public:
  Reflection();
  ~Reflection();
  Reflection(Image i);
};

#endif
