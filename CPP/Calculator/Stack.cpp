#include "Stack.h"
#include <cstddef>

template <class T>
Stack<T>::Stack(){
   top=NULL;
}
template <class T>
Stack<T>::~Stack(){
   Node<T> * nodeptr=top;
   if (isEmpty()) return; 
   while (!isEmpty()) {
      top=top->getNext();
      delete nodeptr;
      nodeptr= top;
   }

}
template <class T>
void Stack<T>::push(T data){
   Node<T>* newptr= new Node<T>(data);
   if (isEmpty()) {
      newptr->setNext(NULL);
      top= newptr;
   }
   else {
      newptr->setNext(top);
      top= newptr;
   }
}

template <class T>
Node<T>* Stack<T>::pop(){
   if (isEmpty()) return NULL;
   Node<T> * nodeptr=top;
   top=top->getNext();
   return nodeptr;

}
template <class T>
Node<T>* Stack<T>::getTop(){
   return top;
}
template <class T>
int Stack<T>::size(){
   int count=0;
   Node<T> * nodeptr=top;
   while(nodeptr){
      ++count;
      nodeptr= nodeptr->getNext();
   }
   return count;
}
template <class T>
bool Stack<T>::isEmpty(){
   if (!top) return true;
   return false;

}
template <class T>
Stack<T>* Stack<T>::reverse(){
   Stack<T> *temp= new Stack<T>;
   Node<T> * nodeptr=top;
   while(nodeptr){
      temp->push(nodeptr->getData());
      nodeptr= nodeptr->getNext();
   } 
   return temp;

}
template <class T>
bool Stack<T>::contains(T data){
   Node<T> * nodeptr=top;
   while(nodeptr && nodeptr->getData()!=data){
      nodeptr= nodeptr->getNext();
   }
   if (!nodeptr) return false;
   return true;

   
}