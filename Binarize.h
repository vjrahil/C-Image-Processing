#ifndef BINARIZE_H_
#define  BINARIZE_H_

#include "Image.h"
#include <iostream>

using namespace std;
class Binarize:public Image
{
public:
    Binarize();
    ~Binarize();
    Binarize(int w,int h);
    Binarize convert1(Image image);
    Binarize convert2(Image image);
};
#endif