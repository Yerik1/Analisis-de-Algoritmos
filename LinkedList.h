//
// Created by yerik on 9/15/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LLNode.h"
class ListaEnlazada {
private:
    LLNode* cabeza;
    int index;

public:
    ListaEnlazada() : cabeza(nullptr), index(0) {}
    ~ListaEnlazada();
    int getPos(int position);
    void setPos(int position, int value);
    void append(int value);
    void deleteNode(int posicion);

};
#include "LinkedList.cpp"
#endif //LINKEDLIST_H
