#ifndef IsGreater_H
#define IsGreater_H

#include "ValueDependantTester.h"

class IsGreater: public ValueDependantTester
{
private:
 static int numAliveObjects;
public:
   IsGreater(int);
   ~IsGreater();
   bool evaluate(int);
   NumberTester* clone();
   static int getNumAliveObjects();
};

#endif
