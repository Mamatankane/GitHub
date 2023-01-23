#include "Game.h"

using namespace std;
Game::Game(int w, int h, std::string chars){
   map= new Map(w,h);
   player=NULL;
   for(int i=0; i<h; i++){
      for(int j=0;j<w; j++){
         switch (chars[j+i*w])
         {
            case '#':
               map->add(new Wall(i,j));
            break;
            
            case '.':
               map->add(new Floor(i,j));
            break;
            case '&':{
               Floor *temp= new Floor(i,j);
               map->add(temp);
               player= new Player(i,j);
               player->above=NULL;
               player->below=temp;
               temp->above=player;
            }
            break;
            case '@':
               exit= new Exit(i,j);
               map->add(exit);
            break;
            case '^':{
               Floor *temp= new Floor(i,j);
               map->add(temp);
               Lamp * light= new Lamp(i,j);
               map->addLight(light);
               light->above=NULL;
               light->below=temp;
               temp->above= light;
            }
            break;
            case '=':
               map->add(new Door(i,j,true));
            break;
            case '+':
               map->add(new Door(i,j,false));
            break;

         }
      }
   }
   messages= new MessageQueue(4);
   map->resetEnvironment();
   map->updateEnvironment();
}
Game::~Game(){
   if (player) delete player;
   delete map;
}

std::string Game::display(){
   return  messages->print()+map->print();
}
inline bool helper(Object * temp,MessageQueue * messages){
   if (!temp->above) return false;
   if (temp->above->getIcon()=='o') {
      Message *m=new Message("Out of bounds");
      messages->addMessage(m);
      delete temp->above;
      temp->above= NULL;
      return true;
   }
   if (temp->above->getIcon()=='w') {
      Message *m=new Message("Walked into something");
      messages->addMessage(m);
      delete temp->above;
      temp->above=NULL;
      return true;
   }
   return false;
}

void Game::update(char input){
   if (!player) {
      Message *m= new Message("Missing player");
      messages->addMessage(m);
      return;
   }
   switch (input)
   {
   case '1':
         player->move(-1,1);
         if (helper(player,messages)) return;


      break;

   case '2':
         player->move(0,1);
         if (helper(player,messages)) return;
      break;

   case '3':
         player->move(1,1);
         if (helper(player,messages)) return;
      break;
   
   case '4':
         player->move(-1,0);
         if (helper(player,messages)) return;
      break;
   case '6':
         player->move(1,0);
         if (helper(player,messages)) return;
      break;

   case '7':
         player->move(-1,-1);
         if (helper(player,messages)) return;
      break;

   case '8':
         player->move(0,-1);
         if (helper(player,messages)) return;
      break;

   case '9':
         player->move(1,-1);
         if (helper(player,messages)) return;
      break;

      case 'e':
         Object * lowest= player;
         while (lowest->below) lowest=lowest->below;
         playerInteract(lowest->getNext(0));
         playerInteract(lowest->getNext(1));
         playerInteract(lowest->getPrev(0));
         playerInteract(lowest->getPrev(1));
      break;
   }
   map->resetEnvironment();
   map->updateEnvironment();
   if (exit==player->below){
      std::string temp="You reached the exit!";
      throw temp;
   } 
   
}

void Game::playerInteract(Object* obj){
   if (!obj) return;
   while(obj->above) obj=obj->above;
   try{
      obj->interact();
   }
   catch(std::string s){
      Message *m=new Message(s);
      messages->addMessage(m);
   }
}