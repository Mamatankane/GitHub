#include "IsDivisible.h"

IsDivisible::IsDivisible(int val): ValueDependantTester(val){
   ++numAliveObjects;
}

IsDivisible::~IsDivisible(){
   --numAliveObjects;
}

bool IsDivisible::evaluate(int val){
   if (val%value==0) return true;
   return false;
}

NumberTester * IsDivisible::clone(){
   IsDivisible * copy= new IsDivisible(value);
   return copy;
}

int IsDivisible::getNumAliveObjects(){
   return numAliveObjects;
}

int IsDivisible::numAliveObjects=0;