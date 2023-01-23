#ifndef IsDivisible_H
#define IsDivisible_H

#include "ValueDependantTester.h"

class IsDivisible: public ValueDependantTester
{
private:
 static int numAliveObjects;
public:
   IsDivisible(int);
   ~IsDivisible();
   bool evaluate(int);
   NumberTester* clone();
   static int getNumAliveObjects();
};


#endif