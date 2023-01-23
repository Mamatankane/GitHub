// Scenario
// For this practical you will be creating an object that represents a matrix that can be resized at the user's behest
#include "matrix.h"

#include <iostream>

using namespace std;

int main() {
    Matrix m = Matrix(0, 0);
    m.displayMatrix();

    cout << endl;
    Matrix m2 = Matrix(6, 6);
    m2.displayMatrix();

    cout << endl;
    Matrix m3 = Matrix(2, 2);
    //m3.setMatrix();
    m3.displayMatrix();

    cout << endl;
    cout<< endl;

    m3.resizeRows(-1);
    m3.resizeColumns(-1);
    m3.displayMatrix();


    m3.resizeRows(10);
    m3.resizeColumns(20);
    m3.displayMatrix();


    m3.resizeRows(2);
    m3.resizeColumns(2);
    m3.setMatrix();
    m3.displayMatrix();


    m3.resizeRows(30);
    m3.resizeColumns(30);
    m3.displayMatrix();


    m3.resizeColumns(-8);
    m3.resizeRows(-5);


    m3.resizeColumns(0);
    m3.resizeRows(0);
    m3.displayMatrix();


    m3.resizeRows(1);
    m3.resizeColumns(1);
    m3.displayMatrix();

    m3.resizeRows(10);
    m3.resizeColumns(10);
    m3.displayMatrix();

    return 0;

}

/* Expected Output
1 1 1
1 1 1
1 1 1

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

1
2
3
4
5
6
7
8
9
1 2 3
4 5 6
7 8 9

Error: cannot have less than 1 row
Error: cannot have less than 1 column

 */