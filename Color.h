#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

class Color
{
  private:
    int _r;
    int _g;
    int _b;

  public:
    Color();
    Color(int r, int g, int b);
    ~Color();
    Color(Color const &c);
    friend ostream & operator << (ostream &op, Color &col);
    friend istream & operator >> (istream &ip, Color &col);
    bool operator ==(Color const &a);
    friend Color& operator+ (Color c,Color t);
    friend Color& operator* (float x,Color c);

    void set_r(int r);
    void set_g(int g);
    void set_b(int b);

    int get_r();
    int get_g();
    int get_b();
};
#endif
