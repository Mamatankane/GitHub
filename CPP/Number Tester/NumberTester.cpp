#include "NumberTester.h"

NumberTester::NumberTester(){
   ++numAliveObjects;
}

NumberTester::~NumberTester(){
   --numAliveObjects;
}

int NumberTester::getNumAliveObjects(){
   return numAliveObjects;
}
int NumberTester::numAliveObjects=0;
