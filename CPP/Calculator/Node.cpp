#include "Node.h"
#include <cstddef>
template <class T>
Node<T>::Node(T data){
   this->data= data;
}
template <class T>
T Node<T>::getData(){
   return data;
}
template <class T>
Node<T>* Node<T>::getNext(){
   return next;
}
template <class T>
void Node<T>::setNext(Node<T>* ptr){
   next= ptr;
}