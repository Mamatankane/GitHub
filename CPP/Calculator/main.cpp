#include <iostream>
#include <string>
#include <sstream>

/*Do not remove this unless you want endless amounts of errors*/
#include "Operator.h"
#include "MinusOperator.h"
#include "MultiplyOperator.h"
#include "PlusOperator.h"
#include "Node.h"
#include "Stack.h"
#include "Calculator.h"
using namespace std;
template <class T>
void test0(){
    Stack<T>* seq= new Stack<T>;
    seq->pop();
}
template <class T>
void test1(int value){
    cout<<"==============testing for "<<value<<"===================="<<endl;
    Stack<T>* seq= new Stack<T>;
    cout<<"is empty "<<seq->isEmpty()<<endl;

    for(int i=0; i<value; i++){
        seq->push(1+ (rand() % 20));
    }
    cout<<"Size: "<<seq->size()<<endl;
    Node<T>* node;
    node= seq->getTop();
    cout<<"seq: ";
    for (int i=0; i<seq->size(); i++){
        cout<<node->getData()<<"  ";
        node= node->getNext();
    }
    cout<<endl;
    cout<<"Popped out: ";
    for(int i=0; i<value; i++){
        node= seq->pop();
        cout<<node->getData()<<"  ";
        delete node;
    }
    cout<<endl;
    cout<<"Size: "<<seq->size()<<endl;
    cout<<"is empty "<<seq->isEmpty()<<endl;
    Stack<T>* seq2= seq->reverse();
    node= seq->getTop();
    cout<<"for original: ";
    for (int i=0; i<seq->size(); i++){
        cout<<node->getData()<<"  ";
        node= node->getNext();
    }
    cout<<endl;
    node= seq2->getTop();
    cout<<"for reversed: ";
    for (int i=0; i<seq2->size(); i++){
        cout<<node->getData()<<"  ";
        node= node->getNext();
    }
    cout<<endl;
    cout<<"contains -8: "<<seq2->contains(-8)<<endl;
    if (seq->size()>0) cout<<"contains "<<seq2->getTop()->getData()<<": "<<seq->contains(seq2->getTop()->getData())<<endl;
    delete seq;
    delete seq2;
    cout<<"===========end of test====================="<<endl;
    

}

template <class T>
void test2(int value){
    cout<<"==============testing for "<<value<<"===================="<<endl;
    Calculator<T>* casio= new Calculator<T>;
    int randval;
    MinusOperator<T> minus;
    PlusOperator<T> plus;
    MultiplyOperator<T> mult;
    Operator<T>* arr[3]={&minus,&plus, &mult};
    for(int i=0; i<value; i++){
       randval=1+ (rand() % 20);
        cout<<randval<<" ";
        casio->addValue(randval);
        
    }
    randval=1+ (rand() % 20);
    cout<<randval<<endl;
    casio->addValue(randval);
    for(int i=0; i<value; i++){
        randval= (rand() % 3);
        casio->addOperator(arr[randval]->clone());
        switch (randval)
        {
            case 0: cout<<"- ";
            break;
            case 1: cout<<"+ ";
            break;
            case 2: cout<<"x ";
            break;
        }
    }
    cout<<" = "<<endl;
    casio->removeValue();
    casio->removeOperator();
        
    cout<<casio->calculate()<<endl;
    delete casio;
    cout<<"===========end of test====================="<<endl;
}
template <class T>
void test3(int value){
    cout<<"==============testing for "<<value<<"===================="<<endl;
    Calculator<T>* casio= new Calculator<T>;
    int randval;
    MinusOperator<T> minus;
    PlusOperator<T> plus;
    MultiplyOperator<T> mult;
    Operator<T>* arr[3]={&minus,&plus, &mult};
    for(int i=0; i<value; i++){
       randval=1+ (rand() % 20);
        cout<<randval<<" ";
        casio->addValue(randval);
        
    }
    if (value>0){
        randval=1+ (rand() % 20);
        cout<<randval<<endl;
        casio->addValue(randval);
        for(int i=0; i<0; i++){
            randval= (rand() % 3);
            casio->addOperator(arr[randval]->clone());
            switch (randval)
            {
                case 0: cout<<"- ";
                break;
                case 1: cout<<"+ ";
                break;
                case 2: cout<<"x ";
                break;
            }
        }
        cout<<" = "<<endl;
    }
    cout<<casio->calculate()<<endl;
    delete casio;
    
    cout<<"===========end of test====================="<<endl;
}
template <class T>
void test4(int value){
    cout<<"==============testing for "<<value<<"===================="<<endl;
    Calculator<T>* casio= new Calculator<T>;
    int randval;
    MinusOperator<T> minus;
    PlusOperator<T> plus;
    MultiplyOperator<T> mult;
    Operator<T>* arr[3]={&minus,&plus, &mult};
    for(int i=0; i<value; i++){
       randval=1+ (rand() % 20);
        cout<<randval<<" ";
        casio->addValue(randval);
        
    }
    if (value>0){
        cout<<endl;
        for(int i=0; i<0; i++){
            randval= (rand() % 3);
            casio->addOperator(arr[randval]->clone());
            switch (randval)
            {
                case 0: cout<<"- ";
                break;
                case 1: cout<<"+ ";
                break;
                case 2: cout<<"x ";
                break;
            }
        }
        cout<<" = "<<endl;
        cout<<casio->calculate()<<endl;
    }
    cout<<casio->calculate()<<endl;
    delete casio;
    cout<<"===========end of test====================="<<endl;
}

int main(){
     for(int i=0; i<5; i++){
        test1<int>(i);
    }
     for(int i=0; i<5; i++){
        test2<int>(i);
    }
     for(int i=0; i<5; i++){
        test3<int>(i);
    }
    for(int i=0; i<5; i++){
        test3<int>(i);
    }
}