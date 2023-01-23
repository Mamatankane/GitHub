#ifndef Lamp_H
#define Lamp_H
#include "Object.h"
class Lamp: public Object{
   public:
      Lamp(int x, int y);
      void update();
};

#endif


