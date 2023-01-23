#ifndef MessageQ_H
#define MessageQ_H
#include "Message.h"
#include <string>
class MessageQueue{
   private:
      int timeout;
      int current;
      Message* head;
      Message *tail;
   public:
      MessageQueue(int timeout);
      std::string print();
      void addMessage(Message* m);
      ~MessageQueue();
};
#endif

