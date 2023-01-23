#ifndef IsEvenOdd_H
#define IsEvenOdd_H

#include "ValueIndependantTester.h"
class IsEvenOdd: public ValueIndependantTester
{
private:
 static int numAliveObjects;
public:
   IsEvenOdd();
   ~IsEvenOdd();
   bool evaluate(int);
   NumberTester* clone();
   static int getNumAliveObjects();
};

#endif