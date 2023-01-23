//The base 2D array class
#ifndef TwoDArray_h
#define TwoDArray_h

//# directives...

//Do not add any more #includes
#include <iostream>
#include <string>

//Define class below
class TwoDArray;
std::ostream& operator<<(std::ostream&, TwoDArray&);

class TwoDArray{
   private:
      int ** array;
      int * sizes;
      int baseSize;
   //////////////
   protected:
      int ** getArray();
      int *getSizes();
      int getBaseSize();
   /////////////
   public:
      TwoDArray(int **, int *, int);
      ~TwoDArray();
      virtual int *operator[](int)=0;
      operator int**();
      operator int*();
      operator int();
      friend std::ostream& operator<<(std::ostream&, TwoDArray&);

};
#endif
