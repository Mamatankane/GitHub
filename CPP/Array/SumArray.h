#ifndef SumArray_h
#define SumArray_h

#include "TwoDArray.h"

class SumArray: public TwoDArray{
   public:
      SumArray(int **, int *, int);
      int * operator[](int);
};
#endif