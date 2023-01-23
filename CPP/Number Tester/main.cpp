// For this practical you will be creating an object that represents a number tester that can be used to test numbers
#include "IsEvenOdd.h"
#include "IsPrimeNumber.h"
#include "IsGreater.h"
#include "IsSmaller.h"
#include "IsDivisible.h"
#include "NumberTester.h"
#include "ValueDependantTester.h"
#include "ValueIndependantTester.h"
#include "TesterInterface.h"
#include <iostream>
using namespace std;
int main(){
   int num=50;
   TesterInterface obj(num);
   NumberTester **arrayoftesters= new NumberTester*[num];
   for(int i=0; i<num;i++ ){
         arrayoftesters[i++]= new IsEvenOdd();
         obj.addTester(arrayoftesters[i]);
         arrayoftesters[i++]= new IsPrimeNumber();
         obj.addTester(arrayoftesters[i]);
         arrayoftesters[i++]= new IsDivisible(i);
         obj.addTester(arrayoftesters[i]);
         arrayoftesters[i++]= new IsGreater(i);
         obj.addTester(arrayoftesters[i]);
      arrayoftesters[i]= new IsGreater(i);
       obj.addTester(arrayoftesters[i]);
      
      
   }
   TesterInterface obj2(&obj);
   cout<<obj2.getCurrNumTesters()<<endl;
   cout<<obj2.getMaxNumTesters()<<endl;
   cout<<obj2.removeTester(4)<<endl;
   cout<<obj2.removeTester(49)<<endl;
   cout<<obj2.removeTester(31)<<endl;
   cout<<obj2.removeTester(4)<<endl;
   cout<<obj2.removeTester(-5)<<endl;
   cout<<obj2.removeTester(60)<<endl;
   IsGreater obj6(9);
   cout<<"#######"<<obj2.addTester(&obj6)<<endl;
   for(int i=0; i<num;i++ ){
     delete arrayoftesters[i++];
     delete arrayoftesters[i++];
     delete arrayoftesters[i++];
     delete arrayoftesters[i++];
     delete arrayoftesters[i];
      
      
   }
   cout<<obj2.getCurrNumTesters();
   cout<<obj2.getMaxNumTesters();
    cout<<obj2[49]<<endl;
   cout<<obj2[4]<<endl;
   cout<<obj2[31]<<endl;
   TesterInterface obj3(obj2);
   obj3.getCurrNumTesters();
   obj3.getMaxNumTesters();
   cout<<obj3[9]<<endl;
   cout<<obj3[4]<<endl;
   cout<<obj3.evaluate(3)<<endl;
   cout<<"=============\n";
   for (int i=0; i<obj3.numberOfFailedTests(3);i++){
      cout<<obj2.failedTests(3)[i]<<endl;
   }
   cout<<"::::::"<<obj3.numberOfFailedTests(3)<<endl;
   cout<<"=============\n";
   for (int i=0; i<obj3.numberOfFailedTests(100);i++){
      cout<<obj2.failedTests(100)[i]<<endl;
   }
   cout<<"::::::"<<obj3.numberOfFailedTests(100)<<endl;
   TesterInterface * obj4=NULL;
   TesterInterface obj5(obj4);
   cout<<obj5.getCurrNumTesters()<<"  "<<obj5.getMaxNumTesters()<<endl;

   
   return 0;  
}