#ifndef Map_H
#define Map_H
#include "ObjectList.h"
#include <string>

class Map{
   private:
      int width;
      int height;
      ObjectList** rows,**columns, *lights;
   public:
      Map(int w,int h);
      ~Map();
      void add(Object* obj);
      std::string print();
      void addLight(Object* I);
      Object* getAt(int x, int y);
      void resetEnvironment();
      void updateEnvironment();

};

#endif


