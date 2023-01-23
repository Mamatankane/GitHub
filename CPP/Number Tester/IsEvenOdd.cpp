#include "IsEvenOdd.h"

IsEvenOdd::~IsEvenOdd(){
   --numAliveObjects;
}

bool IsEvenOdd::evaluate(int val){
   if (val%2==0) return true;
   return false;
}

NumberTester * IsEvenOdd::clone(){
   IsEvenOdd * copy= new IsEvenOdd();
   return copy;
}

IsEvenOdd::IsEvenOdd(){
   ++numAliveObjects;
}
int IsEvenOdd::getNumAliveObjects(){
   return numAliveObjects;
}
int IsEvenOdd::numAliveObjects=0;