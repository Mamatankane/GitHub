#include "IsGreater.h"

IsGreater::~IsGreater(){
   --numAliveObjects;
}

bool IsGreater::evaluate(int val){
   if (val>value) return true;
   return false;
}

NumberTester * IsGreater::clone(){
   IsGreater * copy= new IsGreater(value);
   return copy;
}

IsGreater::IsGreater(int val): ValueDependantTester(val){
   ++numAliveObjects;
}
int IsGreater::getNumAliveObjects(){
   return numAliveObjects;
}
int IsGreater::numAliveObjects=0;