#include "Door.h"

using namespace std;
Door::Door(int x, int y, bool open):Object(x,y){
   if (open) icon='=';
   else icon='+';
   solid=open-1;
}
void Door::interact(){
   if (solid) {
      solid=false;
      icon='=';
      std::string temp="You opened a door";
      throw temp;
   }
   else {
      solid=true;
      icon='+';
      std::string temp="You closed a door";
      throw temp;
   }
}
void Door::updateLight(char direction, int intensity){
   if (solid==false) Object::updateLight(direction, intensity);
   else {
      this->lit=true;
   }
}


