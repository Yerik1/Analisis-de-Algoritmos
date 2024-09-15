//
// Created by yerik on 9/15/24.
//
#include "BTNode.h"
int BTNode::getDato(){
  return dato;
}
void BTNode::setDato(int valor){
  dato = valor;
}
BTNode* BTNode::getIzq(){
  return izquierda;
}
BTNode* BTNode::getDer(){
  return derecha;
}
void BTNode::setIzq(BTNode* izq){
  izquierda = izq;
}
void BTNode::setDer(BTNode* der){
  derecha = der;
}