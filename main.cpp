//
// Created by yerik on 9/15/24.
//

// main.cpp
#include <iostream>
#include "LinkedList.h"
#include "BinaryTree.h"

int main() {
    ListaEnlazada lista;
    lista.append(10);
    lista.append(20);
    lista.append(30);


    lista.deleteNode(1); // Borra el nodo con valor 20
    lista.deleteNode(1); // Borra el nodo con valor 30

    ArbolBinario arbol;
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(70);
    arbol.insertar(60);
    arbol.insertar(80);


    return 0;
}
