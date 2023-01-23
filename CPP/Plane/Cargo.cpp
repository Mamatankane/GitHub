//The Cargo implementation file
#include "Controller.h"

Cargo::Cargo(double w, double ppw): weight(w), value(ppw){

}

std::string Cargo::describe(){
   std::string describ= "Generic cargo <"+std::to_string(value)+"("+std::to_string(weight)+")";
   return describ;
}

double Cargo::getValue() const{
   return value;
}

double Cargo::getWeight() const{
   return weight;
}