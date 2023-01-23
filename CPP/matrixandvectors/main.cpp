// For this assignment, you will create a simplistic mathematical “library” to perform various matrix manipulations and solve systems of linear equations. Operator overloading will be used to
// implement the matrix arithmetic.
#include <iostream>
#include <fstream>
#include "arithmetic.h"
#include "matrix.h"
#include "vector.h"
using namespace std;
////////////////////////////////vector///////////////////////////////////////

void addition(Vector &lhs,Vector &rhs){
    Vector ans(lhs.getSize());
    bool exception=true;
    cout<<"test: +"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs+rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void subtraction(Vector &lhs, Vector &rhs){
    Vector ans(lhs.getSize());
    bool exception=true;
    cout<<"test: -"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs-rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void minusequal(Vector &lhs, Vector &rhs){
    bool exception=true;
    cout<<"test: -="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs-=rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;


}
void plusequal(Vector &lhs, Vector &rhs){
    bool exception=true;
    cout<<"test: +="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs+=rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void powerequal(Vector &lhs,int i=2){
    bool exception=true;
    cout<<"test: ^="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs^=i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void powerof(Vector &lhs,int i=2){
    Vector ans(lhs.getSize());
    bool exception=true;
    cout<<"test: ^"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs^i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void transpose(Vector &lhs){
    Vector ans(lhs.getSize());
    bool exception=true;
    cout<<"test: ~"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans =~lhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void scalarmultple(Vector &lhs,double i=2){
    Vector ans(lhs.getSize());
    bool exception=true;
    cout<<"test: *"<<endl;
    cout<<"Output: "<<endl;
    cout<<"///////object*n////////"<<endl;
    try {
        ans = lhs*i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<"///////n*object////////"<<endl;
    try {
        ans = i*lhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void scalardivision(Vector &lhs,double i=2){
    Vector ans(lhs.getSize());
    bool exception=true;
    cout<<"test: /"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs/i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void scalarmequal(Vector &lhs,double i=2){
    bool exception=true;
    cout<<"test: *="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs*=i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void invoke(unsigned s,unsigned l,int i=0){
    ifstream Input("input.txt");
    Vector lhs(s);
    Vector rhs(l);
    Vector prevstate(s);
    lhs.readFile(Input);
    prevstate=lhs;
    rhs.readFile(Input);
    Input.close();
    cout<<"======================begin=============================="<<endl;
    cout<<"Input: "<<endl;
    cout<<"lhs: "<<endl;
    lhs.print();
    cout<<"rhs: "<<endl;
    rhs.print();
    addition(lhs,rhs);
    subtraction(lhs,rhs);
    plusequal(lhs,rhs);
    lhs=prevstate;
    minusequal(lhs, rhs);
    lhs=prevstate;
    cout<<i<<endl;
    powerequal(lhs,i);
    lhs=prevstate;
    powerof(lhs,i);
    transpose(lhs);
    cout<<i<<endl;
    scalarmultple(lhs,i);
    cout<<i<<endl;
    scalarmequal(lhs,i);
    lhs= prevstate;
    cout<<i<<endl;
    scalardivision(lhs,i);
    cout<<"======================end==============================="<<endl<<endl;
}
///////////////////////matrix///////////////////////////////////
void addition(Matrix &lhs,Matrix &rhs){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: +"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs+rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void subtraction(Matrix &lhs, Matrix &rhs){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: -"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs-rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void minusequal(Matrix &lhs, Matrix &rhs){
    bool exception=true;
    cout<<"test: -="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs-=rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;


}
void plusequal(Matrix &lhs, Matrix &rhs){
    bool exception=true;
    cout<<"test: +="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs+=rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void powerequal(Matrix &lhs,int i=2){
    bool exception=true;
    cout<<"test: ^="<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs^=i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void powerof(Matrix &lhs,int i=2){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: ^"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs^i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void transpose(Matrix &lhs){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: ~"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = ~lhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void scalarmultple(Matrix &lhs,double i=2){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: *"<<endl;
    cout<<"Output: "<<endl;
    cout<<"///////object*n////////"<<endl;
    try {
        ans = lhs*i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<"///////n*object////////"<<endl;
    try {
        ans = i*lhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void scalardivision(Matrix &lhs,double i=2){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: /"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs/i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    cout<<endl;

}
void scalarmequal(Matrix &lhs,double i=2){
    bool exception=true;
    cout<<"test: object*=n"<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs*=i;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}

void matrixmultipleequal(Matrix &lhs,Matrix &rhs){
    bool exception=true;
    cout<<"test: object*=object"<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs*=rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void matrixmultipleof(Matrix &lhs,Matrix &rhs){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: object*object"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs*rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    
    cout<<endl;

}
void uppertriangle(Matrix &lhs,Matrix &rhs){
    Matrix ans(lhs.getRows(),lhs.getCols());
    bool exception=true;
    cout<<"test: object|object"<<endl;
    cout<<"Output: "<<endl;
    try {
        ans = lhs|rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        ans.print();
        cout<<"lhs prev state"<<endl;
        lhs.print();
    }
    
    cout<<endl;

}
void solve(Matrix &lhs,Matrix &rhs){
    bool exception=true;
    cout<<"test: object|=object"<<endl;
    cout<<"Output: "<<endl;
    try {
        lhs|=rhs;
        exception= false;
    }
    catch(const char *p){
        cout<<p<<endl;
    }
    if (!exception){
        lhs.print();
    }
    cout<<endl;

}
void invoke(unsigned sr, unsigned sc,unsigned lr, unsigned lc,int i=0){
    ifstream Input("Input.txt");
    Matrix lhs(sr,sc);
    Matrix rhs(lr,lc);
    Matrix prevstate(sr,sc);
    lhs.readFile(Input);
    prevstate=lhs;
    rhs.readFile(Input);
    cout<<"======================begin=============================="<<endl;
    cout<<"Input: "<<endl;
    cout<<"lhs: "<<endl;
    lhs.print();
    cout<<"rhs: "<<endl;
    rhs.print();
    addition(lhs,rhs);
    subtraction(lhs,rhs);
    plusequal(lhs,rhs);
    lhs=prevstate;
    minusequal(lhs, rhs);
    lhs=prevstate;
    cout<<i<<endl;
    powerequal(lhs,i);
    lhs=prevstate;
    powerof(lhs,i);
    transpose(lhs);
    cout<<i<<endl;
    scalarmultple(lhs,i);
    cout<<i<<endl;
    scalarmequal(lhs,i);
    lhs= prevstate;
    cout<<i<<endl;
    scalardivision(lhs,i);
    matrixmultipleof(lhs,rhs);
    matrixmultipleequal(lhs,rhs);
    lhs=prevstate;
    Matrix B(rhs.getRows(),1),Bprev(rhs.getRows(),1);
    B.readFile(Input);
    Bprev=B;
    cout<<"Matrix B:"<<endl;
    B.print();
    solve(lhs,B);
    uppertriangle(lhs,B);
    solve(lhs,B);
    cout<<"current state of lhs and B"<<endl;
    lhs.print();
    B.print();
    cout<<"=========================================="<<endl;
    lhs=prevstate;
    B= Bprev;
    cout<<"prev state of lhs and B"<<endl;
    lhs.print();
    B.print();
    cout<<"=========================================="<<endl;
    Input.close();
    cout<<"======================end==============================="<<endl<<endl;
}


int main(){
    cout<<"==============Testing Vector========================"<<endl;
    invoke(5,5);
    invoke(5,6,2);
    invoke(3,3,-2);
    invoke(4,3,-1);
    invoke(4,5,4);
    invoke(6,6,5);
    cout<<"==============Testing Matrix========================"<<endl;
    invoke(3,3,3,3);
    invoke(4,4,2,2,1);
    invoke(4,3,3,4,-2);
    invoke(2,3,3,3,2);
    invoke(3,3,3,5,3);
    invoke(2,3,4,5,4);
    invoke(3,4,4,5,6);
    invoke(3,5,2,3,-1);
    invoke(10,10,10,8,2);
    return 0;
}