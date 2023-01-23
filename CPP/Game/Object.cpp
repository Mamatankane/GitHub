#include "Object.h"


Object::Object(int x, int y){
   xPos=x;
   yPos=y;
   icon= '?';
   nextHoriz=nextVert=prevHoriz=prevVert=above=below=NULL;
   lit= true;
}
char Object::getIcon(){ 
   if (lit==false){
      return ' ';
   }
   else{
      Object* cur= this->above, *prev=this;
      while(cur){
         prev=cur;
         cur=cur->above;
      }
      return prev->icon;
   }
}
int Object::getCoord(bool dimension){
   if (dimension) return yPos;
   return xPos;
}
Object * Object::getNext(bool dimension){
   if (dimension) return nextVert;
   return nextHoriz;
}
Object * Object::getPrev(bool dimension){
   if (dimension) return prevVert;
   return prevHoriz;
}
void Object::setNext(Object * obj, bool dim){
   if (dim) nextVert= obj;
   else nextHoriz= obj;

}
void Object::setPrev(Object * obj, bool dim){
   if (dim) prevVert= obj;
   else prevHoriz= obj;
}

void Object::update(){
   lit=false;

}
bool Object::isSolid(){
   Object* cur=this;
   while(cur->above){
      cur=cur->above;
   }
   return cur->solid;
}
void Object::updateLight(char direction, int intensity){
   Object* cur=this;
   switch (direction)
      {
         case 'u': 
            cur->lit=true;
            if (cur->getNext(0)) cur->getNext(0)->lit=true;
            if (cur->getPrev(0)) cur->getPrev(0)->lit=true;
            cur=this->getPrev(1);
         break;
         case 'd': 
            cur->lit=true;
            if (cur->getNext(0)) cur->getNext(0)->lit=true;
            if (cur->getPrev(0)) cur->getPrev(0)->lit=true;
            cur=this->getNext(1);
         break;
         case 'l': 
            cur->lit=true;
            if (cur->getNext(1)) cur->getNext(1)->lit=true;
            if (cur->getPrev(1)) cur->getPrev(1)->lit=true;
            cur=this->getPrev(0);
         break;
         case 'r':
            cur->lit=true;
            if (cur->getNext(1)) cur->getNext(1)->lit=true;
            if (cur->getPrev(1)) cur->getPrev(1)->lit=true;
            cur=this->getNext(0);
         break;
      } 
   if (cur && intensity>1){
      cur->updateLight(direction, intensity-1); 
   }
}
void Object::interact(){
   

}
