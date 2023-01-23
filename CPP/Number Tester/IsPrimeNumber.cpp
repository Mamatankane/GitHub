#include "IsPrimeNumber.h"

IsPrimeNumber::~IsPrimeNumber(){
   --numAliveObjects;
}

bool IsPrimeNumber::evaluate(int val){
   int factors=0;
   for (int i=1; i<val+1; i++){
     if (val%i==0) ++factors;
   }
   if (factors==2) return true;
   return false;
}

NumberTester * IsPrimeNumber::clone(){
   IsPrimeNumber * copy= new IsPrimeNumber();
   return copy;
}

IsPrimeNumber::IsPrimeNumber(){
   ++numAliveObjects;
}
int IsPrimeNumber::numAliveObjects=0;
int IsPrimeNumber::getNumAliveObjects(){
   return numAliveObjects;
}