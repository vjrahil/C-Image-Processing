#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include "CompositeImage.h"
#include "Segmentation.h"
#include "Task2.h"
#include "Histogram.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "ScaledImage.h"
#include "Binarize.h"
#include "Reflection_y.h"
#include <vector>

using namespace std;

void imt2016006(char* fname){
  string _;
  int w,h,__;
  ifstream f1;
  f1.open(fname);
  int abc=255;
  f1>>_;
  f1>>w;
  f1>>h;
  f1>>__;

  Color temp;
  Image i1(w,h);
  float alpha=0.4;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      f1>>temp;
      Pixel p(i,j,temp);
      i1.set_p(p,i,j);
    }
  }

  Segmentation i2(i1,alpha);
  CompositeImage c(i1,i2,alpha);
  ofstream ans("output_task4_imt2016006.ppm");
  ans<<"P3"<<endl;
  ans<<w<<" "<<h<<endl;
  ans<<abc<<endl;
  ans<<c;

}

void imt2016123(char* fname){
  ifstream input_file(fname);
  string mode;
  input_file>>mode;
  int h, w;
  input_file>>w>>h;
  int max;
  input_file>>max;
  ScaledImage& img0 =*(new ScaledImage(w,h));
  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
          int r,g,b;
          input_file>>r>>g>>b;
          Color c(r,g,b);
          Pixel p(i,j,c);
          img0.set_p(p,i,j);
      }
  }
  Image& img1 =*(new Image(w,h));
  img1= img0.create_scaled_image();
  ofstream output_file("output_task7_imt2016123.ppm");
  Pixel& pix = *(new Pixel());
  output_file<<mode<<endl<<w<<" "<<h<<endl<<max<<endl;
  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
          pix=img1.get_p(i,j);
          output_file<<pix<<" ";
      }
  }
}

void imt2016036(char* fname){
  int r1,g1,b1;
	ifstream myfile;
	myfile.open(fname,ios::out);
	ofstream ofile;
	ofile.open("output_task5_imt2016036.ppm");
	int a,b,red,green,blue,range,c;
	float alpha;
	string s;
	myfile>>s>>a>>b>>range;
  Image image(a,b);
	for(int i=0;i < b;i++)
	{
		for(int j=0;j<a;j++)
		{
			myfile>>r1>>g1>>b1;
			Color color(r1,g1,b1);
			Pixel p(i,j,color);
			image.set_p(p,i,j);
		}
    }
	float f=0.2;
    Binarize ans1(image.get_w(),image.get_h());
     ans1.convert1(image);
    Binarize ans2(image.get_w(),image.get_h());
    ans2.convert2(image);
	CompositeImage com(ans2,ans1,f);
  ofile<<"P3"<<endl;
  ofile<<a<<" "<<b<<endl;
  ofile<<range<<endl;
	ofile<<com;
	myfile.close();
	ofile.close();
}

void imt2016062(char* fname){
  float r,g,b,al,grb;
  string en;
  int height,width;
  ifstream fin(fname);
  fin>>en;
  fin>>width;
  fin>>height;
  fin>>grb;
  int abc=255;
  Image img(width,height);
  Color temp;
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      fin>>temp;
      Pixel p(i,j,temp);
      img.set_p(p,i,j);
    }
  }
  Task2 tsk(img);
  vector<Pixel> v = tsk.get_blue_minima();

  Image temp2(width,height);
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      Color co(0,0,0);
      Pixel pi(i,j,co);
      temp2.set_p(pi,i,j);
    }
  }
  int x,y;
  for(int i=0;i<v.size();i++){
    Color c(255,255,255);
    x = v[i].get_x();
    y = v[i].get_y();
    for(int k=-2;k<3;k++){
      for(int l=-2;l<3;l++){
        if(x+k>=0 && x+k<height && y+l>=0 && y+l<width){
          Color co(255,255,255);
          Pixel pi(x+k,y+l,co);
          temp2.set_p(pi,x+k,y+l);
        }
      }
    }
  }
  temp2 = tsk.gaussian(v,temp2);
  ofstream fout3("output_task2_imt2016062.ppm");
  fout3<<"P3"<<endl;
  fout3<<width<<" "<<height<<endl;
  fout3<<abc<<endl;

  int wd1=tsk.get_image().get_w();
  int ht1=tsk.get_image().get_h();
  Image temp3(wd1,ht1);
  for(int i=0;i<ht1;i++){
    for(int j=0;j<wd1;j++){
      int nr1=tsk.get_image().get_p(i,j).get_c().get_r();
      int ng2=tsk.get_image().get_p(i,j).get_c().get_g();
      int nb3=tsk.get_image().get_p(i,j).get_c().get_b();
      Color c1(nr1,ng2,nb3);
      Pixel p1(i,j,c1);
      temp3.set_p(p1,i,j);
    }
  }

  CompositeImage cmpo(temp2,temp3,0.75);
  fout3<<cmpo;
}
void imt2016084(char* fname){
  cout<<"Task "<<"6"<<" not found"<<endl;
}

void imt2016104(char* fname){
  cout<<"Task "<<"1"<<" not found"<<endl;
}


int main(int argc, char *argv[]){

  float alpha=0.4;
  if(argc==2){
    cout<<"Our group task ID combination is: 4,5,2,6,1,7"<<endl;
    imt2016006(argv[1]);
    imt2016123(argv[1]);
    imt2016036(argv[1]);
    imt2016062(argv[1]);
    imt2016084(argv[1]);
    imt2016104(argv[1]);
    cout<<"Rest all done!";
  }

  else if(argc>2){
    cout<<"Our group task ID combination is: ";
    for(int i=2;i<argc;i++){
      if(i==argc-1)
        cout<<*(argv[i])<<endl;
      else
        cout<<*(argv[i])<<",";
      if(*(argv[i])=='4'){
        imt2016006(argv[1]);
      }
      if(*(argv[i])=='5'){
        imt2016036(argv[1]);
      }
      if(*(argv[i])=='2'){imt2016062(argv[1]);}
      if(*(argv[i])=='6'){cout<<"Task "<<*argv[i]<<" not found";}
      if(*(argv[i])=='1'){cout<<"Task "<<*argv[i]<<" not found";}
      if(*(argv[i])=='7'){
      imt2016123(argv[1]);
      }

   }
  }
}
