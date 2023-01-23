#include "Lamp.h"

using namespace std;
Lamp::Lamp(int x, int y):Object(x,y){icon='^';}
void Lamp::update(){
   Object *lowest=this;
   this->lit=true;
   while(lowest->below) 
      lowest= lowest->below;
   lowest->updateLight('l',20);
   lowest->updateLight('r',20);
   lowest->updateLight('u',20);
   lowest->updateLight('d',20);
   
}

