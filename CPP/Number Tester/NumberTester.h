#ifndef NumberTester_H
#define NumberTester_H

class NumberTester
{
private:
   static int numAliveObjects;
public:
   NumberTester();
   virtual ~NumberTester();
   virtual bool evaluate(int)=0;
   virtual NumberTester* clone()=0;
   static int getNumAliveObjects();
   friend class TesterInterface;
};

#endif
