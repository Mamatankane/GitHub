#ifndef IsPrimeNumber_H
#define IsPrimeNumber_H

#include "ValueIndependantTester.h"
class IsPrimeNumber: public ValueIndependantTester
{
private:
 static int numAliveObjects;
public:
   IsPrimeNumber();
   ~IsPrimeNumber();
   bool evaluate(int);
   NumberTester* clone();
   static int getNumAliveObjects();
};


#endif