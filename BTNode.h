//
// Created by yerik on 9/15/24.
//

#ifndef BTNODE_H
#define BTNODE_H
class BTNode {
private:
    int dato;
    BTNode* izquierda;
    BTNode* derecha;
public:
    BTNode(int val) : dato(val), izquierda(nullptr), derecha(nullptr) {}
    int getDato();
    void setDato(int valor);
    BTNode* getIzq();
    BTNode* getDer();
    void setIzq(BTNode* next);
    void setDer(BTNode* next);
};

#include "BTNode.cpp"
#endif //BTNODE_H
