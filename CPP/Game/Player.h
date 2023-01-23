#ifndef Player_H
#define Player_H
#include "Object.h"

class Player: public Object{
   public:
      Player(int x, int y);
      void move(int , int );

};
#endif
