#ifndef SEGMENTATION_H
#define SEGMENTATION_H
#include "Image.h"
#include "Histogram.h"
#include "Reflection.h"
#include "CompositeImage.h"

class Segmentation: public Image{
public:
    Segmentation();
    ~Segmentation();
    Segmentation(Image i,float alpha);
};

#endif
