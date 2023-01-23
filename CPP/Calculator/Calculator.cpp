#include "Calculator.h"
#include <cstddef>

template <class T>
Calculator<T>::Calculator(){
   valueStack= new Stack<T>;
   operatorStack=new Stack<Operator<T>*>;
}
template <class T>
Calculator<T>::~Calculator(){
   valueStack->~Stack();
   operatorStack->~Stack();
}
template <class T>
void Calculator<T>::addValue(T val){
   valueStack->push(val);

}
template <class T>
void Calculator<T>::addOperator(Operator<T>*op){
   operatorStack->push(op);
}
template <class T>
T Calculator<T>::removeValue(){
   if (valueStack->isEmpty()) return NULL;
   return valueStack->pop()->getData();
}
template <class T>
Operator<T>* Calculator<T>::removeOperator(){
   if (operatorStack->isEmpty()) return NULL;
   return operatorStack->pop()->getData();
}
template <class T>
int Calculator<T>::numValues(){
   return valueStack->size();
}
template <class T>
int Calculator<T>::numOperators(){
   return operatorStack->size();
}
template <class T>
T Calculator<T>::calculate(){
   if (numValues()!=numOperators()+1) return NULL;
   while(!operatorStack->isEmpty()){
      T temp1=removeValue();
      T temp2= removeValue();
      Operator<T> * op= removeOperator();
      T ans= (*op)(temp1,temp2);
      addValue(ans);
   }
   return valueStack->getTop()->getData();
   
}