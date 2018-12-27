#ifndef ScaledImage_H_
#define ScaledImage_H_
#include "Image.h"

using namespace std;

class ScaledImage: public Image{
public:
    ScaledImage();
    ScaledImage(int w, int h);
    ~ScaledImage();
    Image& create_scaled_image();
};

#endif
