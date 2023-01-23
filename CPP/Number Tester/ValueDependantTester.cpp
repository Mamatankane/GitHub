#include "ValueDependantTester.h"

ValueDependantTester::ValueDependantTester(int val){
   ++numAliveObjects;
   value=val;
}

ValueDependantTester::~ValueDependantTester(){
   --numAliveObjects;
}

int ValueDependantTester::getNumAliveObjects(){
   return numAliveObjects;
}
int ValueDependantTester::numAliveObjects=0;