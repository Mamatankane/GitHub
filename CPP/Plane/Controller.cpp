//The Controller implementation file
#ifndef Controller_CPP
#define Controller_CPP
#include "Controller.h"
template <class T>
Controller<T>::Controller(Plane<T> * p): plane(p){

}
template <class T>
std::string Controller<T>::loadOnPlane(T* t){
   try {
      plane->add(t);
      return "Success";

   }
   catch (AboveWeightEx p){
      return  "Could not load item, above max weight by "+std::to_string(p.getDifference());
   }
}

template <class T>
double Controller<T>::getTotalValue(){
   try{
      double total=plane->calculateValue();
      return total;
   }
    catch (UndervaluedEx<T> p ){
       plane->remove(p.getUndervalued());
      return p.getSum();

   }
   catch (UnauthorisedEx ){
      return 0;
   }
   catch(EmptyEx ){
      return 0;
   }
  
}
template <class T>
std::string Controller<T>::getPlaneContents(){
   try {
      std::string contents= plane->getDescription();
      return contents;
   }
   catch (EmptyEx){
      return "Nothing to report";
   }
   catch (UnauthorisedEx){
      return "Not permitted";
   }
}

#endif