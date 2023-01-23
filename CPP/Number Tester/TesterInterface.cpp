#include "TesterInterface.h"

#include <cstddef>

TesterInterface::TesterInterface(int maxNumTests){
   if (maxNumTests<1) maxNumTests=0;
   this->maxNumTesters=maxNumTests;
   currNumTesters=0;
   testers= new NumberTester * [maxNumTesters];
   for (int i=0; i<maxNumTesters; i++){
      testers[i]= NULL;
   }
}

TesterInterface::TesterInterface(TesterInterface * other){
   if (other==NULL) {maxNumTesters=0; currNumTesters=0; testers=new NumberTester*[0];}
   else{
      this->maxNumTesters=other->maxNumTesters;
      this->currNumTesters=other->currNumTesters;
      this->testers= new NumberTester *[maxNumTesters];
      for (int i=0; i<maxNumTesters; i++){
          this->testers[i]=other->testers[i];

      }
   }
}

TesterInterface::TesterInterface(TesterInterface& other){
   this->maxNumTesters=other.maxNumTesters;
   this->currNumTesters=other.currNumTesters;
   this->testers= new NumberTester *[maxNumTesters];
   for (int i=0; i<maxNumTesters; i++){
     this->testers[i]=other.testers[i];
   }
}

TesterInterface::~TesterInterface(){
   delete [] testers;
}

int TesterInterface::addTester(NumberTester * tester){
   if (maxNumTesters==currNumTesters) return -1;
   if (tester==NULL) return -1;
   for (int i=0; i<maxNumTesters; i++){
      if (testers[i]==NULL){
         this->testers[i]= tester->clone();
         ++currNumTesters;
         return i;
      }
   }
   return -1;
   
}

bool TesterInterface::removeTester(int pos){
   if (pos>=maxNumTesters || pos<0) return false;
   if (testers[pos]==NULL) return false;
   delete testers[pos];
   testers[pos]=NULL;
   --currNumTesters;
   return true;
}

bool TesterInterface::evaluate(int num){
   if (currNumTesters==0) return false;
   for (int i=0; i<maxNumTesters; i++){
      if (testers[i]!=NULL){
         if (testers[i]->evaluate(num)==false) return false;
      }
   }
   return true;
}

int * TesterInterface::failedTests(int num){
   if (currNumTesters==0) return new int[0];
   int * fails;
   fails= new int[numberOfFailedTests(num)];
   int counter=0;
   for (int i=0; i<maxNumTesters; i++){
      if (testers[i]!=NULL){
         if (testers[i]->evaluate(num)==false) fails[counter++]=i;
      }
   }
   return fails;
}
int TesterInterface::numberOfFailedTests(int num){
   if (currNumTesters==0) return 0;
   int numoffails=0;
   for (int i=0; i<maxNumTesters; i++){
      if (testers[i]!=NULL){
         if (testers[i]->evaluate(num)==false) ++numoffails;
      }
   }
   return numoffails;
}

NumberTester * TesterInterface::operator[](int num){
   if (num<0 || num>maxNumTesters) return NULL;
   return testers[num];
}

int TesterInterface::getMaxNumTesters() const {
   return maxNumTesters;
}

int TesterInterface::getCurrNumTesters() const {
   return currNumTesters;
}


