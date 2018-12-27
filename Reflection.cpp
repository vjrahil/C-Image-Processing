#include "Reflection.h"
#include <iostream>
using namespace std;
Reflection::Reflection(){}

Reflection::~Reflection(){}

Reflection::Reflection(Image i):Image(i.get_w(),i.get_h()){
  int h=i.get_h();
  int w=i.get_w();
  for(int k=0;k<h;k++){
      for(int j=0;j<w;j++){
          int r,g,b;
          r=i.get_p(k,j).get_c().get_r();
          g=i.get_p(k,j).get_c().get_g();
          b=i.get_p(k,j).get_c().get_b();
          Color c(r,g,b);
          Pixel p(k,j,c);
          (*this).set_p(p,k,j);
      }
  }
  for(int k=0;k<h;k++){
      for(int j=0;j<w/2;j++){
        Pixel a;
        a=i.get_p(k,j);
        Pixel b;
        b=i.get_p(k,w-j-1);
        (*this).set_p(b,k,j);
        (*this).set_p(a,k,w-j-1);
      }
  }
}
