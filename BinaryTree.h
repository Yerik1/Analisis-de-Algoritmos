//
// Created by yerik on 9/15/24.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BTNode.h"
#include <iostream>

class ArbolBinario {
private:
    BTNode* raiz;
    BTNode* insertar(BTNode* nodo, int valor);

public:
    ArbolBinario() : raiz(nullptr) {}
    // Función auxiliar para insertar un valor en el árbol
    void insertar(int valor);

    bool buscar(BTNode* nodo, int valor) const;
    void eliminarArbol(BTNode* nodo);
    BTNode* getRaiz() const;
};
#include "BinaryTree.cpp"
#endif //BINARYTREE_H
