#include "chesspiece.h"

int Chesspiece::numberOfPieces=0;
Chesspiece::Chesspiece(){
   name= "";
   type= true;
   numberOfPieces++;
}
Chesspiece::Chesspiece(Chesspiece &obj){
   this->name= obj.name;
   this->type= obj.type;
   numberOfPieces++;

}
Chesspiece::Chesspiece(string in_name){
   this->name= in_name;
   numberOfPieces++;
}
Chesspiece::~Chesspiece(){
   numberOfPieces--;

}
string Chesspiece::getName() const{
   return this->name;
}
bool Chesspiece::getType() const{
   return this->type;
}
int Chesspiece::getNumberOfPieces() const{
    return numberOfPieces;
}
Chesspiece::Chesspiece(string in_name, bool in_type){
   this->name= in_name;
   this->type= in_type;
   numberOfPieces++;
}
