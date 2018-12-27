#include <bits/stdc++.h>
#include "ScaledImage.h"


using namespace std;

ScaledImage::ScaledImage(){}
ScaledImage::ScaledImage(int w, int h):Image(w, h){}
ScaledImage::~ScaledImage(){}

Image& ScaledImage::create_scaled_image(){
    Image& rimg = *(new Image(this->get_w(), this->get_h()));
    // this for the top left part..
    // plus i have used a different algo then what mam gave..
    for(int i=0;i<this->get_h();i++){
        for(int j=0;j<this->get_w();j++){
            if(i%2==0 && j%2==0 && i!=this->get_h()-1 && j!=this->get_w()-1){
                int red=this->get_p(i,j).get_c().get_r()+this->get_p(i+1,j).get_c().get_r()+this->get_p(i,j+1).get_c().get_r()+this->get_p(i+1,j+1).get_c().get_r();
                red/=4;
                int green=this->get_p(i,j).get_c().get_g()+this->get_p(i+1,j).get_c().get_g()+this->get_p(i,j+1).get_c().get_g()+this->get_p(i+1,j+1).get_c().get_g();
                green/=4;
                int blue=this->get_p(i,j).get_c().get_b()+this->get_p(i+1,j).get_c().get_b()+this->get_p(i,j+1).get_c().get_b()+this->get_p(i+1,j+1).get_c().get_b();
                blue/=4;
                Color c(red,green,blue);
                Pixel p(i/2,j/2,c);
                rimg.set_p(p,i/2,j/2);
            }
            else if(i%2==0 && j%2==0)
            {
            	int red=this->get_p(i,j).get_c().get_r();
                int green=this->get_p(i,j).get_c().get_g();
                int blue=this->get_p(i,j).get_c().get_b();
                Color c(red,green,blue);
                Pixel p(i/2,j/2,c);
                rimg.set_p(p,i/2,j/2);
            }
        }
    }
    // copies the top left part on the top right part..
    for(int i=0;i<=this->get_h()/2;i++){
        for(int j=0;j<=this->get_w()/2;j++){
            // Color c = rimg.get_p(i,j).get_c();
            int r=rimg.get_p(i,j).get_c().get_r();
            int g=rimg.get_p(i,j).get_c().get_g();
            int b=rimg.get_p(i,j).get_c().get_b();
            Color c(r,g,b);
            Pixel p(i/2,j/2,c);
            rimg.set_p(p,i,this->get_w()-j-1);
        }
    }
    // inverts the upper part to the lower part. hence giving the reflection image..
    for(int i=0;i<this->get_h()/2;i++){
        for(int j=0;j<this->get_w();j++){
            int r=rimg.get_p(i,j).get_c().get_r();
            int g=rimg.get_p(i,j).get_c().get_g();
            int b=rimg.get_p(i,j).get_c().get_b();
            Color c(r,g,b);
            Pixel p(i,j,c);
            rimg.set_p(p,this->get_h()-i-1,j);
        }
    }
    // your this part is different then mine..
    for(int i=0;i<rimg.get_h();i++){
        for(int j=0;j<rimg.get_w();j++){
            if((i>=rimg.get_h()/4 && i<3*rimg.get_h()/4) && (j>=rimg.get_w()/4 && j<3*rimg.get_w()/4)) ;
            else{
                int r=255,g=255,b=255;
                Color c(r,g,b);
                Pixel p(i,j,c);
                rimg.set_p(p,i,j);
            }
        }
    }

    return rimg;
}
