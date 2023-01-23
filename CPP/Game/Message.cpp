#include "Message.h"

using namespace std;
Message::Message(std::string t){
   text=t;
}
std::string Message::getText(){
   return text;
}


