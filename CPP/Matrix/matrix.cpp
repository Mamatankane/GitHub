#include <iostream>

#include "matrix.h"

using namespace std;
Matrix::Matrix(int in_rows, int in_columns){
    if (in_rows<1 || in_columns<1){
        rows=3;
        columns=3;
        matrix=new int**[rows];

        for (int i=0; i<rows; i++){
            matrix[i]= new int *[columns];
            for (int j=0; j<columns; j++){
                matrix[i][j]= new int;
                *matrix[i][j]= 1;
            }
        }
    }
    else{
        rows=in_rows;
        columns=in_columns;
        matrix=new int**[rows];
        for (int i=0; i<rows; i++){
            matrix[i]= new int *[columns];
            for (int j=0; j<columns; j++){
                matrix[i][j]= new int;
                *matrix[i][j]= 0;
            }
        }    
    }
}
Matrix::~Matrix(){
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            delete matrix[i][j];
        }
        delete [] matrix[i];
    }
    delete [] matrix;
}
void Matrix::resizeColumns(int num_cols){
    if (num_cols<1){
        std::cout<<"Error: cannot have less than 1 column"<<std::endl;
    }
    else{
        int *** newmatrix=new int**[rows];
        
        if (num_cols>columns){
            for (int i=0; i<rows; i++){
                newmatrix[i]= new int *[num_cols];
                for (int j=0; j<columns; j++){
                    newmatrix[i][j]= new int;
                    *newmatrix[i][j]= *matrix[i][j];
                }
                for (int j=columns; j<num_cols; j++){
                    newmatrix[i][j]= new int;
                    *newmatrix[i][j]= 0;
                }
                
            } 
        }
        else {
            for (int i=0; i<rows; i++){
                newmatrix[i]= new int *[num_cols];
                for (int j=0; j<num_cols; j++){
                    newmatrix[i][j]= new int;
                    *newmatrix[i][j]= *matrix[i][j];
                }  
            }
        } 
        for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                delete matrix[i][j];
            }
            delete [] matrix[i];
        }
            delete [] matrix;
        matrix= newmatrix;
        columns= num_cols;
            
    }        
}
void Matrix::resizeRows(int num_rows){
     if (num_rows<1){
        std::cout<<"Error: cannot have less than 1 row"<<std::endl;
    }
    else{
        int *** newmatrix=new int**[num_rows];
        if (num_rows>rows){
            for (int i=0; i<rows; i++){
                newmatrix[i]= new int *[columns];
                for (int j=0; j<columns; j++){
                    newmatrix[i][j]= new int;
                    *newmatrix[i][j]= *matrix[i][j];
                }
            } 
            for (int i=rows; i<num_rows; i++){
                newmatrix[i]= new int *[columns];
                for (int j=0; j<columns; j++){
                    newmatrix[i][j]= new int;
                    *newmatrix[i][j]= 0;
                }
            } 
        }
        else{
            for (int i=0; i<num_rows; i++){
                newmatrix[i]= new int *[columns];
                for (int j=0; j<columns; j++){
                    newmatrix[i][j]= new int;
                    *newmatrix[i][j]= *matrix[i][j];
                }
            } 

        }

        for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                delete matrix[i][j];
            }
            delete [] matrix[i];
        }
            delete [] matrix;
        matrix= newmatrix;
        rows= num_rows;
            
    }        

}
void Matrix::setMatrix(){
    for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                std::cin>>*matrix[i][j];
            }
        } 
}
//Do not change the displayMatrix() function
void Matrix::displayMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            cout << *matrix[i][j];

            if (j != columns - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }
}