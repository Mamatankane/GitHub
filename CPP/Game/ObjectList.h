#ifndef ObjectList_H
#define ObjectList_H
#include "Object.h"
#include <string>

class ObjectList{
   private:
      bool dimension;
      Object * head, *current;
   public:
      ObjectList(bool dim);
      void add(Object* obj);
      Object* getHead();
      std::string print();
      void reset();
      Object* iterate();
      std::string debug();
};

#endif
