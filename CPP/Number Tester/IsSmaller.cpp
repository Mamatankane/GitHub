#include "IsSmaller.h"


IsSmaller::~IsSmaller(){
   --numAliveObjects;
}

bool IsSmaller::evaluate(int val){
   if (val<value) return true;
   return false;
}

NumberTester * IsSmaller::clone(){
   IsSmaller * copy= new IsSmaller(value);
   return copy;
}

IsSmaller::IsSmaller(int val): ValueDependantTester(val){
   ++numAliveObjects;
}
int IsSmaller::getNumAliveObjects(){
   return numAliveObjects;
}
int IsSmaller::numAliveObjects=0;