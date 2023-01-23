#ifndef Object_H
#define Object_H
#include <sstream>

class Object{
   protected:
      char icon;
      int xPos, yPos;
      bool solid;
      bool lit;
   public:
      Object* nextHoriz,*nextVert, *prevHoriz, *prevVert, *above, *below;
      Object(int x, int y);
      char getIcon();
      int getCoord(bool dimension);
      Object * getNext(bool dimension);
      Object * getPrev(bool dimension);
      void setNext(Object * obj, bool dim);
      void setPrev(Object * obj, bool dim);
      virtual void update();
      bool isSolid();
      virtual void updateLight(char direction, int intensity);
      virtual void interact();
};

#endif
