
#include "matrix.h"
#include <iomanip>
#include <sstream>

Matrix::Matrix(unsigned r, unsigned c){
   rows=r;
   cols=c;
   matrix= new double *[r];
   for (int i=0; i<r; i++){
      matrix[i]=new double [c];
      for (int j=0; j<c; j++){
         matrix[i][j]=0;
      }
   }
}
Matrix::Matrix(const Matrix& rhs){
   this->rows= rhs.rows;
   this->cols= rhs.cols;
   this->matrix= new double *[this->rows];
   for (int i=0; i<this->rows; i++){
      this->matrix[i]= new double [this->cols];
      for (int j=0; j<this->cols; j++){
         this->matrix[i][j]= rhs.matrix[i][j];
      }
   }

}
Matrix::~Matrix(){
   for (int i=0; i<rows; i++){
      delete [] matrix[i];
   }
   delete [] matrix;

}

void Matrix::readFile(istream &infile){
   for (int i=0; i<rows; i++){
      for (int j=0; j<cols; j++){
         infile>>matrix[i][j];
      } 
      
   }

}

void Matrix::print(){
   for (int i=0; i<rows; i++){
      for (int j=0; j<cols; j++){
         cout<<setw(10)<<setprecision(3)<<matrix[i][j];
      }
      cout<<endl;
   }  
}

unsigned Matrix::getRows() const{
   return rows;
}
unsigned Matrix::getCols() const{
   return cols;
}

double& Matrix::operator()(const unsigned r, const unsigned c){
   if (r>rows || c>cols){
      throw "Error: invalid row index";
   }
   return matrix[r][c];

}
const double& Matrix::operator()(const unsigned r, const unsigned c) const{
   if (r>rows || c>cols){
      throw "Error: invalid row index";
   }
   return matrix[r][c];
}

Vector Matrix::operator[](const unsigned r) const{
   if (r>rows){
      throw "Error: invalid row index";
   }
   Vector vec(cols);
   for (int i=0; i<cols; i++){
      vec[i]=matrix[r][i];
   }
   return vec;
  
}

const Matrix& Matrix::operator=(const Matrix& rhs){
   if (&rhs==this) return *this;
   for (int i=0; i<rows; i++){
      delete [] matrix[i];
   }
   delete [] matrix; 
   matrix = new double* [rhs.rows];
   rows = rhs.rows;
   cols= rhs.cols;
   for (int r=0; r<rows; r++){
     matrix[r]=new double [cols];
      for (int c=0; c<cols; c++){
         matrix[r][c]=rhs.matrix[r][c];
      }
   }
   return *this;
}

Matrix& Matrix::operator=(Matrix& rhs){
   if (&rhs==this) return *this;
   for (int i=0; i<rows; i++){
      delete [] matrix[i];
   }
   delete [] matrix; 
   matrix = new double* [rhs.rows];
   rows = rhs.rows;
   cols= rhs.cols;
   for (int r=0; r<rows; r++){
     matrix[r]=new double [cols];
      for (int c=0; c<cols; c++){
         matrix[r][c]=rhs.matrix[r][c];
      }
   }
   return *this;
}


Matrix Matrix::operator*(const double& rhs){
   Matrix mat(rows, cols);
  for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
         mat.matrix[r][c]=matrix[r][c]*rhs;
      }
   }
   return mat;
}

Matrix operator*(const double& rhs, Matrix &matrix){
   return matrix*rhs;
}

Matrix& Matrix::operator*=(const double& rhs){
   for (int r=0; r<rows; r++){
      for(int c=0; c<cols; c++){
         matrix[r][c]*=rhs;
      }
   }
   return *this;
}
Matrix Matrix::operator/(const double& rhs){
   if (rhs==0) throw "Error: division by zero";
   Matrix mat(rows, cols);
   for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
         mat.matrix[r][c]=matrix[r][c]/rhs;
      }
   }
   return mat;
}

Matrix Matrix::operator+(const Matrix& rhs){
   if (rows!=rhs.rows || cols!=rhs.cols) throw "Error: adding matrices of different dimesionality";
   Matrix mat(rows, cols);
   for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
         mat.matrix[r][c]= matrix[r][c]+rhs[r][c];
      }
   }
   return mat;
} 
Matrix& Matrix::operator+=(const Matrix& rhs){
    if (rows!=rhs.rows || cols!= rhs.cols) throw "Error: adding matrices of different dimesionality";
    for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
          matrix[r][c]+=rhs.matrix[r][c];
      }
   }
   return *this;
}
Matrix Matrix::operator-(const Matrix& rhs){
   if (rows!=rhs.rows || cols!=rhs.cols) throw "Error: Subtracting matrices of different dimesionality";
   Matrix mat(rows, cols);
   for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
          mat.matrix[r][c]=matrix[r][c]-rhs[r][c];
      }
   }
   return mat;
}
Matrix& Matrix::operator-=(const Matrix& rhs){
   if (rows!= rhs.rows || cols!=rhs.cols) throw "Error: Subtracting matrices of different dimesionality";
    for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
         matrix[r][c]-=rhs[r][c];
      }
   }
   return *this;
}

Matrix Matrix::operator~(){
   Matrix mat(cols, rows);
   for (int r=0; r<rows; r++){
      for (int c=0; c<cols; c++){
         mat.matrix[c][r]=matrix[r][c];
      }
   }
   return mat;

}
Matrix Matrix::operator*(const Matrix& rhs){
   if (cols!= rhs.rows){
      throw "Error: invalid matrix multiplication";
   }
   Matrix mat(rows, rhs.cols);
   for (int r=0; r<mat.rows; r++){
      for (int c=0; c<mat.cols; c++){
         double result=0;
         for (int i=0; i<cols; i++){
            result+= this->matrix[r][i]*rhs.matrix[i][c];
         }
         mat.matrix[r][c]=result;
      }
   }
   return mat;
}
Matrix& Matrix::operator*=(const Matrix& rhs){
   (*this)= (*this)*rhs;
   return *this;
}
Matrix Matrix::operator^(int pow){
   if (pow<0) throw "Error: negative power is not supported";
   if (rows!=cols) throw "Error: non-square matrix provided";
   Matrix mat(rows,cols),temp(rows,cols);
   mat= *this;
   if (pow==0) {
      for (int r=0; r<mat.rows; r++){
         for (int c=0; c<mat.cols; c++){
           if (c==r) mat.matrix[r][c]=1;
           else mat.matrix[r][c]=0;
         }
      }   
   }
   else{
      for (int i=1; i<pow; i++){
         temp= mat;
         for (int r=0; r<mat.rows; r++){
            for (int c=0; c<mat.cols; c++){
               double result=0;
               for (int i=0; i<cols; i++){
                  result+= temp.matrix[r][i]*this->matrix[i][c];
               }
               mat.matrix[r][c]=result;
            }
         }
      }
   }
   return mat;
}
Matrix& Matrix::operator^=(int pow){
   (*this)= (*this)^pow;
   return *this;
}

Matrix& Matrix::operator|=(Matrix& rhs){
   if (rows!=cols ){
      throw "Error: non-square matrix provided";
   }
   if (rhs.cols!=1 ||rhs.rows!=rows){
      throw "Error: incorrect augmentation";
   }
   int m;
   for (int j=0; j<rows-1; j++){
      for (int i=j+1; i<cols; i++){
         if (matrix[j][j]==0){
             throw "Error: division by zero";
         }
         m= matrix[i][j]/matrix[j][j];
         for (int k=0; k<rows; k++){
            matrix[i][k]=matrix[i][k]-m*matrix[j][k];
         }
         rhs.matrix[i][0]=rhs.matrix[i][0]-m *rhs.matrix[j][0];
      }
   }
   return *this;

}


Matrix Matrix::operator|(const Matrix& rhs){
   if (rows!=cols ){
      throw "Error: non-square matrix provided";
   }
   if (rhs.cols!=1){
      throw "Error: incorrect augmentation";
   }
   Matrix mat(*this);
   Matrix b(rhs); 
   for (int i=0; i<rows; i++){
      for (int j=0; j<i; j++){
         if (mat.matrix[i][j]!=0) {
            mat|=b;
            break;
         }
      }
   }
   Matrix solutions(b); 
   for (int i=rows-1; i>=0;i--){
      for (int j=i+1; j<rows;j++){
         solutions.matrix[i][0]= solutions.matrix[i][0] - mat.matrix[i][j]*solutions.matrix[j][0];
      }
      if (mat.matrix[i][i]==0) {
         throw "Error: division by zero";
      }
      solutions.matrix[i][0]= solutions.matrix[i][0]/ mat.matrix[i][i];
   }
   return solutions;
}


