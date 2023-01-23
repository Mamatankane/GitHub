#ifndef IsSmaller_H
#define IsSmaller_H

#include "ValueDependantTester.h"
class IsSmaller: public ValueDependantTester
{
private:
 static int numAliveObjects;
public:
   IsSmaller(int);
   ~IsSmaller();
   bool evaluate(int);
   NumberTester* clone();
   static int getNumAliveObjects();
};



#endif