
#include "vector.h"
#include <iomanip>


Vector::Vector(unsigned s){
   if (s<0) s=0;
   size=s;
   vector= new double [s];
   for (int i=0; i<s; i++){
      vector[i]=0;
   }
}
Vector::Vector(const Vector& rhs){
   this->size=rhs.size;
   this->vector= new double [this->size];
   for (int i=0; i<this->size; i++){
      this->vector[i]=rhs.vector[i];
   }
}
Vector::~Vector(){
   delete [] this->vector;
}

void Vector::readFile(istream &infile){
   for (int i=0; i<size; i++){
      infile>>vector[i];
   }
}

void Vector::print(){
   for (int i=0; i<size; i++){
      cout<<setw(10)<<setprecision(3)<<vector[i];
   }   
   cout<<endl;
}

double& Vector::operator[](const unsigned r){
   if (r>size) throw "Error: invalid row index";
   return vector[r];
}
const double& Vector::operator[](const unsigned r) const{
   if (r>size) throw "Error: invalid row index";
   return vector[r];
}
unsigned Vector::getSize() const{
   return size;
} 

Vector Vector::operator*(const double& rhs){
   Vector vec(size);
   for (int i=0; i<size; i++){
      vec.vector[i]= vector[i]*rhs;
   }
   return vec;
}
Vector operator*(const double& rhs, Vector &vector){
   return vector*rhs;
}
Vector& Vector::operator*=(const double& rhs){
   for (int i=0; i<size; i++){
      vector[i]*=rhs;
   }
   return *this;
}
Vector Vector::operator/(const double& rhs){
   if (rhs==0) throw "Error: division by zero";
   Vector vec(size);
   for (int i=0; i<size; i++){
      vec.vector[i]=vector[i]/rhs;
   }
   return vec;
}

Vector Vector::operator+(const Vector& rhs){
   if (size!=rhs.size) throw  "Error: adding vectors of different dimensionality";
   Vector vec(size);
   for (int i=0; i<size; i++){
      vec.vector[i]=vector[i]+rhs[i];
   }
   return vec;
}
Vector& Vector::operator+=(const Vector& rhs){
   if (size!=rhs.size) throw "Error: adding vectors of different dimensionality";
    for (int i=0; i<size; i++){
      vector[i]+=rhs[i];
   }
   return *this;
}
Vector Vector::operator-(const Vector& rhs){
   if (size!=rhs.size) throw "Error: subtracting vectors of different dimensionality";
   Vector vec(size);
   for (int i=0; i<size; i++){
      vec.vector[i]=vector[i]-rhs[i];
   }
   return vec;

}
Vector& Vector::operator-=(const Vector& rhs){
   if (size!=rhs.size) throw "Error: subtracting vectors of different dimensionality";
    for (int i=0; i<size; i++){
      vector[i]-=rhs[i];
   }
   return *this;
}
Vector Vector::operator^(int pow){
   if (pow<0) throw "Error: negative power is not supported";
   Vector vec(size);
   for (int i=0; i<size; i++){
      vec.vector[i]=1;
      for (int j=0; j<pow; j++){
         vec.vector[i]*=vector[i];
      }
   }
   return vec;
}
Vector& Vector::operator^=(int pow){
   if (pow<0) throw "Error: negative power is not supported";
   Vector vec(*this);
   for (int i=0; i<size; i++){
      vector[i]=1;
      for (int j=0; j<pow; j++){
         vector[i]*=vec.vector[i];
      }
   }
   return *this;
}
Vector Vector::operator~(){
   Vector vec(size);
   for (int i=0; i<size; i++){
      vec.vector[i]=vector[size-i-1];
      
   }
   return vec;
}

const Vector& Vector::operator=(const Vector& rhs){
   if (&rhs==this) return *this;
   delete [] vector; 
   vector = new double [rhs.size];
   size = rhs.size;
   for (int i=0; i<this->size; i++){
      this->vector[i]=rhs.vector[i];
   }
   return *this;
}
Vector& Vector::operator=(Vector& rhs){
   if (&rhs==this) return *this;
   delete [] vector; 
   vector = new double [rhs.size];
   size = rhs.size;
   for (int i=0; i<this->size; i++){
      this->vector[i]=rhs.vector[i];
   }
   return *this;
}