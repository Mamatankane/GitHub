#ifndef SortArray_h
#define SortArray_h

#include "TwoDArray.h"

class SortArray: public TwoDArray{ 
   public:
      SortArray(int**,int*, int);
      int * operator[](int);
};
#endif