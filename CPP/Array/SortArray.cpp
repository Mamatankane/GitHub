#include "SortArray.h"
#include <iostream>


SortArray::SortArray(int ** array, int *sizes, int baseSize): TwoDArray(array, sizes, baseSize)
{

}
int * SortArray::operator[](int index){
   int * array= getArray()[index];
         for (int i=0; i<getSizes()[index]-1; i++)	{
            for (int j=i+1; j<getSizes()[index]; j++){
               if (array[i]>array[j]){
                  int temp= array[j];
                  array[j]=array[i];
                  array[i]=temp;
               }

            }
         }
			return array;
}