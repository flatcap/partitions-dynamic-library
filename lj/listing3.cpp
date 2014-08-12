#ifndef __SQUARE_H
#define __SQUARE_H
#include "shape.hh"
class square : public shape {
public:
   void draw();
};
#endif // __SQUARE_H
#include <iostream>
#include "square.hh"
void square::draw(){
   // simple ascii square
   cout << "\n";
   cout << "    *********\n";
   cout << "    *       *\n";
   cout << "    *       *\n";
   cout << "    *       *\n";
   cout << "    *       *\n";
   cout << "    *********\n";
   cout << "\n";
}
extern "C" {
shape *maker(){
   return new square;
}
class proxy { public:
   proxy(){
      // register the maker with the factory
      factory["square"] = maker;
   }
};
// our one instance of the proxy
proxy p;
}
