#include "CountArray.h"
#include <iostream>

CountArray::CountArray(int ** array, int *sizes, int baseSize): TwoDArray(array, sizes, baseSize)
{

}
int * CountArray::operator[](int index){
   return &getSizes()[index];
}