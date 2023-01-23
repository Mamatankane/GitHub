//The Controller class
#ifndef Controller_H
#define Controller_H

#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"

//See spec for inclusion strategy for templates
template <class T>
class Controller
{
private:
   Plane<T> *plane;
public:
   Controller(Plane<T>*);
   double getTotalValue();
   std::string getPlaneContents();
   std::string loadOnPlane(T* t);
};

#include "Controller.cpp"



#endif 