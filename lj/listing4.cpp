#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include "shape.hh"
// size of buffer for reading in directory entries
static unsigned int BUF_SIZE = 1024;
// our global factory for making shapes
map<string, maker_t *, less<string> > factory;
int main(int argc, char **argv){
   FILE *dl;   // handle to read directory
   char *command_str = "ls *.so";  // command
               // string to get dynamic lib names
   char in_buf[BUF_SIZE]; // input buffer for lib
                          // names
   list<void *> dl_list; // list to hold handles
                               // for dynamic libs
   list<void *>::iterator itr;
vector<string> shape_names;  // vector of shape
               // types used to build menu
   list<shape *> shape_list;  // list of shape
               // objects we create
   list<shape *>::iterator sitr;
map<string, maker_t *, less<string> >::iterator fitr;
   // get the names of all the dynamic libs (.so
              // files) in the current dir
   dl = popen(command_str, "r");
   if(!dl){
      perror("popen");
      exit(-1);
   }
   void *dlib;
   char name[1024]; i
   while(fgets(in_buf, BUF_SIZE, dl)){
      // trim off the whitespace
      char *ws = strpbrk(in_buf, " \t\n");
      if(ws) *ws = '\0';
      // append ./ to the front of the lib name
      sprintf(name, "./%s", in_buf);
      dlib = dlopen(name, RTLD_NOW);
      if(dlib == NULL){
         cerr << dlerror() << endl;
         exit(-1);
      }
      // add the handle to our list
      dl_list.insert(dl_list.end(), dlib);
   }
   int i = 0;
   // create an array of the shape names
   for(fitr=factory.begin(); fitr!=factory.end();
        fitr++){
      shape_names.insert(shape_names.end(),
        fitr->first);
      i++;
   }
   int choice;<\n>
   // create a menu of possible shapes to create and let the user make some
   while(1){
      i = 1;
      for(fitr=factory.begin();
           fitr!=factory.end(); fitr++){
         cout << i << " - Create " << fitr->first
            << endl;
         i++;
      }
      cout << i << " - Draw created shapes\n";
      i++; i
      cout << i << " - Exit\n";
      cout << "> ";
      cin >> choice;
      if(choice == i){
         // destroy any shapes we created
         for(sitr=shape_list.begin();
              sitr!=shape_list.end();sitr++){
            delete *sitr;
         }
         // close all the dynamic libs we opened
         for(itr=dl_list.begin(); itr!=dl_list.end(); itr++){
            dlclose(*itr);
         }
         exit(1);
      }
      if(choice == i - 1){
         // draw the shapes
         for(sitr=shape_list.begin();
              sitr!=shape_list.end();sitr++){
            (*sitr)->draw();
         }
      }
      if(choice > 0 && choice < i - 1){
         // add the appropriate shape to the shape list
         shape_list.insert(shape_list.end(),
            factory[shape_names[choice-1]]());
      }
   }
}

