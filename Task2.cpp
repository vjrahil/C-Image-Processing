#include <iostream>
#include <vector>
#include <fstream>
#include "Task2.h"

  Color  Task2::get_Color_x_y(Image ori,int x,int y){

    // Pixel p= ori.get_p(x,y);
    int r = ori.get_p(x,y).get_c().get_r();
    int g = ori.get_p(x,y).get_c().get_g();
    int b = ori.get_p(x,y).get_c().get_b();
    Color c(r,g,b);
    return c;
  }
  Task2::Task2(Image &ori) : A(ori.get_w(), ori.get_h()){
    Image t(ori.get_w(),ori.get_h());
    Color temp;
    for(int i =0;i<ori.get_h();i++){
      for(int j=0;j<ori.get_w();j++){
        temp = get_Color_x_y(ori,i,j);
        //t.setColor(i,ori.get_w()-j-1,temp.get_r(),temp.get_g(),temp.get_b());
        Color co(temp.get_r(),temp.get_g(),temp.get_b());
        Pixel pi(i,ori.get_w()-j-1,temp);
        t.set_p(pi,i,ori.get_w()-j-1);

      }
    }
    //Color co(r,g,b);
    //Pixel pi(x,y,co);
    //Image.set_p(pi,x,y);

    float r,g,b,al,grb;
    string en;
    int height,width;
    A = t;
  }
  Image Task2::get_image(){
    return A;
  }

  vector<Pixel> Task2::get_blue_minima(){
    vector<Pixel> v;
    int count;
    for(int i=0;i<A.get_h();i++){
      for(int j=0;j<A.get_w();j++){
        count=0;
        if (i>0 && j>0 && get_Color_x_y(A,i-1,j-1).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(i>0 && get_Color_x_y(A,i-1,j).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(i>0 && j+1<A.get_w() && get_Color_x_y(A,i-1,j+1).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(j>0 && get_Color_x_y(A,i,j-1).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(j+1<A.get_w() && get_Color_x_y(A,i,j-1).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(i+1<A.get_h() && j>0 && get_Color_x_y(A,i+1,j-1).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(i+1<A.get_h() && get_Color_x_y(A,i+1,j).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }
        if(i+1<A.get_h() && j+1<A.get_w() && get_Color_x_y(A,i+1,j+1).get_b()>get_Color_x_y(A,i,j).get_b()){
          count++;
        }

        if(count==8){
          int nr=A.get_p(i,j).get_c().get_r();
          int ng=A.get_p(i,j).get_c().get_g();
          int nb=A.get_p(i,j).get_c().get_b();
          Color c(nr,ng,nb);
          Pixel p(i,j,c);
          v.push_back(p);
        }
      }
    }

    return v;
  }

  Image Task2::gaussian(vector<Pixel> v,Image img){
    int g[5][5] = {{1,4,7,4,1},
                   {4,16,26,16,4},
                 {7,26,41,26,7},{4,16,26,16,4},{1,4,7,4,1}};
    for(int i=0;i<v.size();i++){
      int x = v[i].get_x();
      int y = v[i].get_y();
      int x1,x2,y1,y2;
      x1 = ((x-2)<0?0:(x-2));
      x2 = ((x-2)<0?(2-x):0);
      y1 = ((y-2)<0?0:(y-2));
      y2 = ((y-2)<0?(2-y):0);
      for(;x1<=x+2 && x1<img.get_h();x1++,x2++){
        int a_y = y1;
        int a_y1 = y2;
        for(;a_y<=y+2 && a_y<img.get_w();a_y++,a_y1++){
          int temp = int((255*g[x2][a_y1])/273);
          if(get_Color_x_y(img,x1,a_y1).get_r()!=255){
            temp+=get_Color_x_y(img,x1,a_y1).get_r();
            temp/=2;
          }
          Color co(temp,temp,temp);
          Pixel pi(x1,a_y,co);
          img.set_p(pi,x1,a_y);
          //img.setColor(x1,a_y,temp,temp,temp);
        }
      }
    }
    Image temp = img;

    return temp;
  }
