//The Passenger class
#ifndef Passenger_H
#define Passenger_H

#include <sstream>
#include <string>

class Passenger 
{
   private:
      std::string ID;
      double weight;
      double ticketPrice;

   public:
      Passenger(std::string, double,double);
      double getWeight();
      double getValue();
      std::string describe();
};

#endif
