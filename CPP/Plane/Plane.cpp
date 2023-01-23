//The Plane implementation file
#ifndef Plane_CPP
#define Plane_CPP
#include "Plane.h"
#include "Exceptions.h"

template <class T>
Plane<T>::Plane(double max): maxWeight(max){

}

template <class T>
Plane<T>::~Plane(){
   for (int i=0; i<cargo.size(); i++){
      delete cargo[i];
   }
}

template <class T>
void Plane<T>::add(T* item){
   double size=0;
      for (int i=0; i<cargo.size(); i++){
         size+=cargo[i]->getWeight();
      }
   size+=item->getWeight();
   if (size>maxWeight) {
      throw AboveWeightEx(maxWeight-item->getWeight());
   } 
   cargo.push_back(item);
}

template <class T>
void Plane<T>::remove(T* item){
   if (cargo.size()==0){
      throw EmptyEx();
   }
   int i;
   for (i=0; i<cargo.size();i++){
      if (cargo[i]==item) break;
   }
   if (i>= cargo.size() ){
      throw NotFoundEx<T>(item);
   }
   cargo.erase(cargo.begin()+i);
}
template <class T>
std::string Plane<T>::getDescription(){
    if (cargo.size()==0){
      throw EmptyEx();
   }   
   std::string result;
   int i;
   for (i=0; i<cargo.size()-1; i++){
      result+= cargo[i-1]->describe()+'\n';
   }
   result+= cargo[i]->describe();
   return result;
}
std::string Plane<SecretCargo>::getDescription(){
    if (cargo.size()==0){
      throw EmptyEx();
   }
   throw UnauthorisedEx();
   
}
template <class T>
double Plane<T>::calculateValue(){
      if (cargo.size()==0) throw EmptyEx();
      double size=0;
      for (int i=0; i<cargo.size();i++){
         for (int j=i+1; j<cargo.size();j++){
            if (cargo[i]->getWeight()<cargo[j]->getWeight()){
               T* temp= cargo[i];
               cargo[i]=cargo[j];
               cargo[j]=temp;
            }
         }
      }
      int i;
      for (i=0; i<cargo.size()-1; i++){
         size+=cargo[i]->getWeight();
      }
      if ((double) cargo[i]->getWeight()/cargo[i-1]->getWeight()<0.5) throw UndervaluedEx<T>(cargo[i],size);
      return size;
}

double Plane<SecretCargo>::calculateValue(){
    if (cargo.size()==0){
      throw EmptyEx();
   }
   throw UnauthorisedEx();
   
}
#endif