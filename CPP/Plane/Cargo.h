//The Cargo class
#ifndef Cargo_H
#define Cargo_H

#include <string>
#include <sstream>

class Cargo
{
   private:
      double weight;
      double value;

   public:
      Cargo(double , double);
      std::string describe();
      double getWeight() const;
      double getValue() const;
};


#endif
