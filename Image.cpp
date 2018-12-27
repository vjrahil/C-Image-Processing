#include "Image.h"
#include <iostream>

using namespace std;

Image::Image(int w,int h){
  _w=w;
  _h=h;
  // std::cout << "sdfs" << '\n';
  _p=new Pixel*[h];
  for(int i=0;i<h;i++){
    _p[i]=new Pixel[w];
  }
}

Image::Image(){};

Image::Image(Image &i): _w(i._w), _h(i._h), _p(i._p){}


Pixel Image::get_p(int x,int y){
  return _p[x][y];
}
Pixel& Image::get_pr(int x,int y){
  return _p[x][y];
}

void Image::set_p(Pixel p,int x,int y){
  _p[x][y]=p;
}

ostream & operator << (ostream &out, Image &i){
  for(int j=0;j<i._h;j++){
    for(int k=0;k<i._w;k++){
      out<<i._p[j][k]<<" ";
    }
    out<<endl;
  }
  return out;
}

int Image::get_w(){
  return _w;
}

int Image::get_h(){
  return _h;
}

Image& Image::operator=(Image const &other) {
  _h = other._h;
  _w = other._w;
  for(int i=0;i<_h;i++) {
    for(int j=0;j<_w;j++) {
      _p[i][j] = other._p[i][j];
    }
  }
  return *(this);
}

// Image& operator+(Image &image1, Image &image2){
//   if(image1.get_w() == image2.get_w() && image1.get_h() == image2.get_h()){
//     int w1 = image1.get_w();
//     int h1 = image1.get_h();
//     Image& result(w1, h1);
//     for(int i=0;i<result.get_h();i++) {
//       for(int j=0;j<result.get_w();j++) {
//         int new_r = image1.get_p(i, j).get_c().get_r() + image2.get_p(i, j).get_c().get_r();
//         int new_g = image1.get_p(i, j).get_c().get_g() + image2.get_p(i, j).get_c().get_g();
//         int new_b = image1.get_p(i, j).get_c().get_b() + image2.get_p(i, j).get_c().get_b();
//         if(new_r>255)new_r=255;
//         if(new_g>255)new_g=255;
//         if(new_b>255)new_b=255;
//         Color c(new_r,new_g,new_b);
//         Pixel p(i,j,c);
//         result.set_p(p,i,j);
//       }
//     }
//     return result;
//   }
// }
//
// Image& operator*(float f, Image &image) {
//   Image& tmp_image(image.get_w(), image.get_h());
//   for(int i=0;i<image.get_h();i++) {
//     for(int j=0;j<image.get_w();j++) {
//       int new_r = f*(image._p[i][j].get_c().get_r());
//       int new_g = f*(image._p[i][j].get_c().get_g());
//       int new_b = f*(image._p[i][j].get_c().get_b());
//       if(new_r>255)new_r=255;
//       if(new_g>255)new_g=255;
//       if(new_b>255)new_b=255;
//       Color c(new_r,new_g,new_b);
//       Pixel p(i,j,c);
//       tmp_image.set_p(p,i,j);
//     }
//   }
//   return tmp_image;
// }
