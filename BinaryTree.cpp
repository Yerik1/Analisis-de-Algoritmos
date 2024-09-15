//
// Created by yerik on 9/15/24.
//
#include "BinaryTree.h"
void ArbolBinario::insertar(int valor) {
    raiz= insertar(raiz, valor);
}

BTNode* ArbolBinario::insertar(BTNode* node, int valor) {
    if (!node) {
        return new BTNode(valor);
    }

    if (valor < node->getDato()) {
        node->setIzq(insertar(node->getIzq(), valor));
    } else if (valor > node->getDato()) {
        node->setDer(insertar(node->getDer(), valor));
    }

    return node;
}

bool ArbolBinario::buscar(BTNode* node, int valor) const{
    if (!node) {
        return false;
    }

    if (valor == node->getDato()) {
        return true;
    } else if (valor < node->getDato()) {
        return buscar(node->getIzq(), valor);
    } else {
        return buscar(node->getDer(), valor);
    }

}

void ArbolBinario::eliminarArbol(BTNode* node){
    if (!node) {
        return;
    }

    eliminarArbol(node->getIzq());
    eliminarArbol(node->getDer());
    delete node;
}

BTNode* ArbolBinario::getRaiz() const {

  return raiz;
}