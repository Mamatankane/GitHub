#ifndef ValueDependant_H
#define ValueDependant_H

#include "NumberTester.h"

class ValueDependantTester: public NumberTester
{
private:
   static int numAliveObjects;
protected:
    int value;
public:
   ValueDependantTester(int);
   virtual ~ValueDependantTester();
   virtual bool evaluate(int)=0;
   virtual NumberTester* clone()=0;
   static int getNumAliveObjects();
};



#endif
