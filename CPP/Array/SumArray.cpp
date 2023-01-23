#include "SumArray.h"
#include <iostream>

SumArray::SumArray(int ** array, int *sizes, int baseSize): TwoDArray(array, sizes, baseSize)
{

}
int * SumArray::operator[](int index){
   int *sum = new int(0);
         for (int i=0; i<getSizes()[index]; i++)	{
            (*sum)+=getArray()[index][i];
         }
			return sum;
}