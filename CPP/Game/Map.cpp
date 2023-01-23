#include "Map.h"
using namespace std;

Map::Map(int w,int h){
   width=w;
   height=h;
   if (h<0 || w<0) {
      width=0;
      height=0;
   }
   lights= new ObjectList(0);
   rows= new ObjectList*[height];
   columns= new ObjectList*[width];
   for(int i=0; i<height; i++){
      rows[i]= new ObjectList(0);
   }
   for(int i=0; i<width; i++){
      columns[i]= new ObjectList(1);
   }
}
Map::~Map(){
     for(int i=0; i<height; i++){
      Object* cur=rows[i]->getHead(),*prev=rows[i]->getHead();
      rows[i]->reset();
      while(prev){
         cur=rows[i]->iterate();
         delete prev;
         prev= cur;
      }
      delete rows[i];
   }
   for(int i=0; i<width; i++){
      delete columns[i];
   }
   delete [] rows;
   delete [] columns;
}
void Map::add(Object* obj){
   if (!obj) return;
   rows[obj->getCoord(0)]->add(obj);
   columns[obj->getCoord(1)]->add(obj);
}
string Map::print(){
   string temp;
   for(int i=0; i<height; i++){
      temp=temp+rows[i]->print()+'\n';
   }
   return temp;
}
void Map::addLight(Object* light){
   lights->add(light);
}
Object* Map::getAt(int x, int y){
   if (rows[x]==NULL) return NULL;
   rows[x]->reset();
   Object * cur=rows[x]->getHead();
   for(int i=0; i<y && cur; i++) cur=rows[x]->iterate();
   return cur;


}
void Map::resetEnvironment(){
   for(int i=0; i<height; i++){
      Object*cur=rows[i]->getHead();
      rows[i]->reset();
      while(cur){
         cur->update();
         cur= rows[i]->iterate();
      }
   }
}
void Map::updateEnvironment(){
   Object * cur=lights->getHead();
   lights->reset();
   while(cur){
      cur->update();
      cur= lights->iterate();
   }
}

