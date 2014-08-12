#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "shape.hh"
class circle : public shape {
public:
   void draw();
};
#endif // __CIRCLE_H
#include <iostream> #include "circle.hh"
void circle::draw(){
   // simple ascii circle<\n>
   cout << "\n";
   cout << "      ****\n";
   cout << "    *      *\n";
   cout << "   *        *\n";
   cout << "   *        *\n";
   cout << "   *        *\n";
   cout << "    *      *\n";
   cout << "      ****\n";
   cout << "\n";
}
extern "C" {
shape *maker(){
   return new circle;
}
class proxy {
public:
   proxy(){
      // register the maker with the factory
      factory["circle"] = maker;
   }
};
// our one instance of the proxy
proxy p;
}
