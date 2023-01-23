#include "TwoDArray.h"
#include <iostream>
TwoDArray::TwoDArray(int ** array, int * sizes, int baseSize){
   this->baseSize= baseSize;
   this->sizes= new int[baseSize];
   this->array= new int *[baseSize];
   for (int i=0; i<baseSize; i++){
      this->sizes[i]= sizes[i];
      this->array[i]= new int[sizes[i]];
      for (int j=0; j<sizes[i]; j++){
         this->array[i][j]=array[i][j];
         
      }
   }

}
TwoDArray::~TwoDArray(){
   for(int i=0; i<baseSize; i++){
      delete [] array[i];
   }
   delete [] sizes;
   delete [] array;
}
std::ostream& operator<<(std::ostream& obj, TwoDArray& Array){
   for (int i=0; i<Array.baseSize;i++){
      obj<<Array.array[i][0];
      for (int j=1; j<Array.sizes[i]; j++){
         obj<<" "<<Array.array[i][j];
      }
      obj<<"\n";
   }
   return obj;
}
int ** TwoDArray::getArray(){
   int ** newArray= new int*[baseSize];
   for (int i=0; i<baseSize; i++){
      newArray[i]=new int[sizes[i]];
      for( int j=0; j<sizes[i]; j++){
         newArray[i][j]= array[i][j];
      }
   }
   return newArray;

}
int * TwoDArray::getSizes(){
   int *newArray=new int[baseSize];
   for (int i=0; i<baseSize; i++){
      newArray[i]=sizes[i];
   }
   return newArray;

}
int TwoDArray::getBaseSize(){
   return baseSize;

}
TwoDArray::operator int**(){
   return getArray();

}
TwoDArray::operator int*(){
   return getSizes();
}
TwoDArray::operator int(){
   return getBaseSize();   
}