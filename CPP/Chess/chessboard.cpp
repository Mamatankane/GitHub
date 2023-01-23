#include "chessboard.h"

Chessboard::Chessboard(Chessboard &obj){
   this->rows= obj.rows;
   this->columns= obj.columns;
   this->board= new Chesspiece **[rows];
   for (int i=0; i<rows; i++){
      board[i]= new Chesspiece *[columns];
      for (int j=0; j<columns; j++){
        if (obj.board[i][j]!=NULL) {
            board[i][j]= new Chesspiece(*obj.board[i][j]);
        }
        else board[i][j]=NULL;
      }
   }
}
Chessboard::Chessboard(int in_rows, int in_columns){
   this->rows= in_rows;
   this->columns= in_columns;
   this->board= new Chesspiece **[rows];
   for (int i=0; i<rows; i++){
      board[i]= new Chesspiece *[columns];
      for (int j=0; j<columns; j++){
         board[i][j]= NULL;
      }
   }
}
Chessboard::~Chessboard(){
   for (int i=0; i<rows; i++){
      for (int j=0; j<columns; j++){
         delete this->board[i][j];
      }
      delete [] this->board[i];
   }
   delete [] this->board;
}
void Chessboard::addChesspiece(Chesspiece *piece, int row, int column){
   board[row][column]= piece;

}
 void Chessboard::removeChesspiece(int row, int column){
   delete board[row][column];
   board[row][column]= NULL;

 }
Chesspiece &Chessboard::at(int row, int column) const{
   return *board[row][column];
 }
 Chessboard &Chessboard::operator=(const Chessboard &other){
    for (int i=0; i<rows; i++){
      for (int j=0; j<columns; j++){
         delete this->board[i][j];
      }
      delete [] this->board[i];
   }
   delete [] this->board;
   this->rows= other.rows;
   this->columns= other.columns;
   this->board= new Chesspiece **[rows];
   for (int i=0; i<rows; i++){
      this->board[i]= new Chesspiece *[columns];
      for (int j=0; j<columns; j++){
        if (other.board[i][j]!=NULL) {
            this->board[i][j]= new Chesspiece(*other.board[i][j]);
        }
        else this->board[i][j]=NULL;
      }
   }
   return *this;
 }
 Chessboard &Chessboard::operator+=(const Chessboard &rhs){
   for (int i=0; i<rows; i++){
      for (int j=0; j<columns; j++){
         if (this->board[i][j]==NULL && rhs.board[i][j]!=NULL)
            this->board[i][j]= new Chesspiece(*rhs.board[i][j]);
      }
   }
   return *this;
 }
