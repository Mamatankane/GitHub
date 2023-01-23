#include "MessageQueue.h"

using namespace std;
MessageQueue::MessageQueue(int timeout){
   this->timeout= timeout;
   current=timeout;
   tail=head=NULL;

}
std::string MessageQueue::print(){
   Message* cur=head;
   std::string temp;
   while(cur && current>0){
      temp+=cur->getText()+'\n';
      cur=cur->next;
      --current;
   }
   if (current==0){
      cur=head;
      head=head->next;
      delete cur;
      current=timeout;
   }
   return temp;

}
void MessageQueue::addMessage(Message* m){
   if (!tail){
      head=tail=m;
   }
   else {
      tail->next=m;
      tail= m;
   }
   m->next= NULL;
}
MessageQueue::~MessageQueue(){

    Message* cur=head;
   while(cur){
      head=head->next;
      delete cur;
      cur= head;
   }
   
}

