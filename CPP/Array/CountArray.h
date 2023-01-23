#ifndef CountArray_h
#define CountArray_h

#include "TwoDArray.h"

class CountArray: public TwoDArray{
   public:
      CountArray(int **, int *, int);
      int * operator[](int);
};
#endif