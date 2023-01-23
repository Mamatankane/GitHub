#include "Player.h"

using namespace std;
Player::Player(int x, int y):Object(x,y){icon='&';}
void Player::move(int xdifference, int ydifference){
   Object *swap,*lowest=this;
   char tempicon='T';
   while(lowest->below) lowest=lowest->below; 
   if (xdifference==1 && ydifference==0) swap= lowest->nextHoriz;
   if (xdifference==-1 && ydifference==0) swap=lowest->prevHoriz;
   if (xdifference==0 && ydifference==1) swap= lowest->nextVert;
   if (xdifference==0 && ydifference==-1) swap=lowest->prevVert;

   if (xdifference==1 && ydifference==1){
      if (lowest->nextHoriz) swap=lowest->nextHoriz->nextVert;
      else if (lowest->nextVert) swap= lowest->nextVert->nextHoriz;
      if (!lowest->nextHoriz && !lowest->nextVert) {
         tempicon='o';
      }
      else if (lowest->nextHoriz->isSolid() && lowest->nextVert->isSolid()) {
         tempicon='w';
      }
   }
   if (xdifference==-1 && ydifference==1) {
      if (lowest->prevHoriz) swap= lowest->prevHoriz->nextVert;
      else if (lowest->nextHoriz) swap= lowest->nextVert->prevHoriz;
      if (!lowest->nextHoriz && !lowest->prevHoriz) {
         tempicon='o';
      }
      else if (lowest->nextHoriz->isSolid() && lowest->prevHoriz->isSolid()) {
         tempicon='w';
      }
   }
   if (xdifference==1 && ydifference==-1) {
      if (lowest->nextHoriz) swap= lowest->nextHoriz->prevVert;
      else if (lowest->prevVert) swap= lowest->prevVert->nextHoriz;
      if (!lowest->nextHoriz && !lowest->prevVert) {
         tempicon='o';
      }
      else if (lowest->nextHoriz->isSolid() && lowest->prevVert->isSolid()) {
         tempicon='w';
      }
   }
   if (xdifference==-1 && ydifference==-1) {
      if (lowest->prevHoriz) swap= lowest->prevHoriz->prevVert;
      else if (lowest->prevVert) swap= lowest->prevVert->prevHoriz;
      if (!lowest->prevHoriz && !lowest->prevVert) {
         tempicon='o';
      }
      else if (lowest->prevHoriz->isSolid() && lowest->prevVert->isSolid()) {
         tempicon='w';
      }
   }
   if (!swap) tempicon='o';
   else if (swap->isSolid() || swap->isSolid()) tempicon='w';
   if (tempicon!='T'){
      Player * tempplayer= new Player(0,0);
      tempplayer->icon=tempicon;
      this->above= tempplayer;
      return;
   }
   while(swap->above) swap=swap->above;
   swap->above=this;
   this->below->above=this->above;
   this->below=swap;
   this->above=NULL;
}
