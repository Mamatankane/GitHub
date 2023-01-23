//The Plane class
#ifndef Plane_H
#define Plane_H

#include <vector>
#include "Exceptions.h"
#include "SecretCargo.h"

template <class T>
class Plane{
   private:
      std::vector<T*> cargo;
      double maxWeight;
   public:
      Plane(double);
      ~Plane();
      void add(T*);
      void remove(T*);
      std::string getDescription();
      double calculateValue();
};

template <>
class Plane<SecretCargo>{
   private:
      std::vector<SecretCargo> cargo;
      double maxWeight;
   public:
      Plane(double);
      ~Plane();
      void add(SecretCargo*);
      void remove(SecretCargo*);
      std::string getDescription();
      double calculateValue();
};

//See spec on inclusion strategy for templates
#include "Plane.cpp"
#endif
