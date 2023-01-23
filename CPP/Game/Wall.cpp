#include "Wall.h"

using namespace std;

Wall::Wall(int x, int y):Object(x,y){icon='#'; solid=true;}
void Wall::updateLight(char direction, int intensity){
   this->lit=true;
}