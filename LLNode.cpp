//
// Created by yerik on 9/15/24.
//

#include "LLNode.h"

int LLNode::getDato(){
  return dato;
}

void LLNode::setDato(int valor){
  dato = valor;
}

LLNode* LLNode::getNext(){
  return siguiente;
}

void LLNode::setNext(LLNode* next){
  siguiente = next;
}