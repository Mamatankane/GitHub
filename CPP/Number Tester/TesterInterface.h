#ifndef TesterInterface_H
#define TesterInterface_H

#include "NumberTester.h"
class TesterInterface
{
private:
   int maxNumTesters;
   int currNumTesters;
   NumberTester ** testers;
public:
   TesterInterface(int);
   TesterInterface(TesterInterface*);
   TesterInterface(TesterInterface&);
   ~TesterInterface();
   int addTester(NumberTester*);
   bool removeTester(int);
   bool evaluate(int);
   int * failedTests(int);
   int numberOfFailedTests(int);
   NumberTester * operator[](int);
   int getCurrNumTesters() const;
   int getMaxNumTesters() const;
};

#endif

