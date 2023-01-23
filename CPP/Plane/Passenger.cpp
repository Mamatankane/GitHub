//The Passenger implementation file
#include "Passenger.h"
Passenger::Passenger(std::string id, double w, double t): ID(id), weight(w), ticketPrice(t){

}

std::string Passenger::describe(){
   std::string describ=ID+" <"+std::to_string(ticketPrice)+">"+"("+std::to_string(weight)+")";
   return describ;
}

double Passenger::getWeight(){
   return weight;
}

double Passenger::getValue(){
   return ticketPrice;
}