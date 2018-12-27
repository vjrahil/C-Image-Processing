#include "CompositeImage.h"
#include <iostream>
#include <cstdlib>

CompositeImage::CompositeImage() {

}

CompositeImage::CompositeImage(Image a, Image b, float alpha):
  Image(a.get_w(), a.get_h()){
    if(a.get_w() == b.get_w() && a.get_h() == b.get_h()) {
      for(int i=0;i<_h;i++) {
        for(int j=0;j<_w;j++) {
          int r = alpha*(b.get_pr(i,j).get_c().get_r()) + (1-alpha)*(a.get_pr(i,j).get_c().get_r());
          int g = alpha*(b.get_pr(i,j).get_c().get_g()) + (1-alpha)*(a.get_pr(i,j).get_c().get_g());
          int b1 = alpha*(b.get_pr(i,j).get_c().get_b()) + (1-alpha)*(a.get_pr(i,j).get_c().get_b());
          Color c(r, g, b1);
          Pixel &p = *(new Pixel(b.get_pr(i,j).get_x(), b.get_pr(i,j).get_y(), c));
          _p[i][j]=p;
        }
      }
    }
}

CompositeImage::~CompositeImage() {

}
