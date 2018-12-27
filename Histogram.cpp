#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Histogram.h"
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

using namespace std;

Histogram::Histogram(){}

Histogram::~Histogram(){}

Histogram::Histogram(Image i,int f):brightness(i.get_h(),vector <int> (i.get_w())){
  int h=i.get_h();
  int w=i.get_w();

  // vector< vector <int> > brightness(h,vector <int> (w));

  for(int k=0;k<h;k++){
    for(int j=0;j<w;j++){
      Color c;
      c=i.get_p(k,j).get_c();
      brightness[k][j]=(c.get_r()+c.get_b()+c.get_g())/3;
    }
  }
  vector <int> histogram(256,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      histogram[brightness[i][j]]++;
    }
  }
if(f==1){  int factor = 6;
  for(int i=factor-1;i<255-factor-1;i++){
    int ctr = 0;
    for(int j=0;j<factor;j++){
      if(histogram[i-j]>histogram[i] && histogram[i]<=histogram[i+j])
          ctr++;
    }
    // cout<<ctr<<endl;
    if(ctr == factor-1){
      threshold.push_back(i);
    }
  }}
if(f==2){  for(int i=1;i<255;i++){
    if(histogram[i]<histogram[i-1] && histogram[i+1]>histogram[i] && histogram[i]!=0 && histogram[i+1]!=0 && histogram[i-1]!=0 )
      threshold.push_back(i);
  }}
  // cout<<threshold.size()<<endl;
}

vector<int> Histogram::getThreshold(){
  return threshold;
}

vector< vector<int> > Histogram::getBrightness(){
  return brightness;
}
