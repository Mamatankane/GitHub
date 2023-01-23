#include "ObjectList.h"

using namespace std;
ObjectList::ObjectList(bool dim){
   dimension=dim;
   head=current=NULL;   
}
void ObjectList::add(Object* obj){
   if (!obj) return;
   if (!head){
      head=obj;
      obj->setNext(NULL,dimension);
      obj->setPrev(NULL,dimension);
   } 
   else{
      Object *cur=head;
      Object* prev= NULL; 
      while(cur && cur->getCoord(dimension-1)<obj->getCoord(dimension-1)){
         prev= cur;
         cur= cur->getNext(dimension);
      }
      if (!prev){
         obj->setNext(head,dimension);
         obj->setPrev(NULL,dimension);
         head->setPrev(obj, dimension);
         head=obj;
      } 
      else if (!cur){
         obj->setNext(NULL,dimension);
         obj->setPrev(prev,dimension);
         prev->setNext(obj, dimension);
      } 
      else{
         obj->setNext(cur,dimension);
         obj->setPrev(prev,dimension);
         prev->setNext(obj, dimension);
         cur->setPrev(obj,dimension);
      }
   }
}
Object* ObjectList::getHead(){
   return head;
}
string ObjectList::print(){
   Object * cur=head;
   string temp;
   while(cur){
      Object* s=cur;
      while(s->above) s= s->above;
      temp+=cur->getIcon();
      cur=cur->getNext(dimension);
   }
   return temp;
}
void ObjectList::reset(){
   current= head;
}
Object* ObjectList::iterate(){
   if (!current) return NULL;
   current=current->getNext(dimension);
   return current;
}
inline std::string asstring(int x){
   std::stringstream s;
   s<<x;
   return s.str();
}
string ObjectList::debug(){
   string temp;
   Object* cur=head,*prev=NULL;
    temp+="Forward:\n";
   while(cur){
      temp=temp+ '<'+cur->getIcon()+'>'+" at ("+asstring(cur->getCoord(0))+','+asstring(cur->getCoord(1))+") Top:";
      if (cur->above!=NULL) temp+= 'N';
      else temp+="Y";
      temp+='\n';
      prev=cur;
      cur=cur->getNext(dimension);
   }
   cur=prev;
   temp+="Back:\n";
   while(cur){
      temp=temp+ '<'+cur->getIcon()+'>'+" at ("+asstring(cur->getCoord(0))+','+asstring(cur->getCoord(1))+") Top:";
      if (cur->above!=NULL) temp+= 'N';
      else temp+="Y";
      temp+='\n';
      cur=cur->getPrev(dimension);   
   }
   return temp;
}
