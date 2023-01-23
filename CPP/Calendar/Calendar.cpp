#include "Calendar.h"

using namespace std;

Calendar::Calendar(){
   head=NULL;
}
Calendar::Calendar(vector<event_data>input){
   head=NULL;
   int i=0;
   while(input.size()!=i){
      createEvent(input[i]);
      ++i;
   }


}
Calendar::~Calendar(){
  
}
Event * Calendar::getUpcomingEvent(long int now){
   Event * cur=head;
   while (cur && cur->start<now){
      cur= cur->next;
   }
   return cur;
}
vector<Event> Calendar::filterEvents(int* id, long int * start, long int *end, string *type){
   Event * cur=head;
   bool removed=true;
   vector<Event> vec;
   while (cur){
      if (id && cur->id!=*id) removed=false;
      if (start && cur->start<=*start) removed= false;
      if (end && cur->end>=*end) removed=false;
      if (type && cur->type!=*type) removed=false;
      if (removed==true) vec.push_back(*cur);
      removed=true;
      cur= cur->next;
   }
   return vec;
}
void Calendar::alterEvent(int id, long int * end, string *type){
   Event * cur=head;
   while (cur){
      if (cur->id==id){
         if (end) cur->end= *end;
         if (type) cur->type= *type;
         break;
      }
      cur= cur->next;
   }
}
void Calendar::removeEvent(int id){
   Event * cur=head,* prev=NULL;
   while (cur && cur->id!=id){
      prev=cur;
      cur= cur->next;
   } 
   if (cur==NULL){
      return;
   }
   if (prev==NULL ){
      head=head->next;
      delete cur;
      return;
   }
   prev->next=cur->next;
   delete cur;

}
void Calendar::createEvent(event_data data){
   Event* cur=head, * prev=NULL;
   Event * newnode= new Event(to_long(data.start), to_long(data.end), to_int(data.id), to_string(data.type));
   while (cur && cur->start<=to_long(data.start)){
      prev=cur;
      cur= cur->next;
   }
   if (head==NULL) {
      head= newnode;
      return ;
   }
   if(prev==NULL){
      newnode->next= head;
      head=newnode;
      return ;
   }
   newnode->next= cur;
   prev->next= newnode;


}
void Calendar::clearCalendar(){
   Event * cur=head, *prev=NULL;
   while(cur){
      prev=cur;
      cur=cur->next;
      delete prev;
   }
   head=NULL;
}
Event * Calendar::getFirstEvent(){
   return head;
}
ostream& operator<<(ostream& out, Calendar& calendar){
   Event * cur=calendar.getFirstEvent();
   int i=0;
   while (cur){
      out<<i++<<": "<<cur->type<<" "<<unix_to_string(cur->start)<<"->"<<unix_to_string(cur->end)<<endl;
      cur=cur->next;
   }
   return out;
}