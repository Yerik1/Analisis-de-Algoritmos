//
// Created by yerik on 9/15/24.
//

#ifndef LLNODE_H
#define LLNODE_H

class LLNode {
    private:
        int dato;
        LLNode* siguiente;
    public:
        LLNode(int valor) : dato(valor), siguiente(nullptr) {}
        int getDato();
        void setDato(int valor);
        LLNode* getNext();
        void setNext(LLNode* next);
};
#include "LLNode.cpp"
#endif //LLNODE_H
