//
// Created by yerik on 9/15/24.
//

#include "LinkedList.h"

ListaEnlazada::~ListaEnlazada() {
    LLNode* actual = cabeza;
    while (actual) {
        LLNode* siguiente = actual->getNext();
        delete actual;
        actual = siguiente;
    }
}

int ListaEnlazada::getPos(int position) {

    LLNode* actual = cabeza;
    int pos = 0;
    while (actual) {
        if(pos == position) {
            return actual->getDato();
        }else {
            LLNode* siguiente = actual->getNext();
            actual = siguiente;
            pos++;
        }

    }
    return -1;
}

void ListaEnlazada::setPos(int position, int value) {

    LLNode* actual = cabeza;
    int pos = 0;
    while (actual) {
        if(pos == position) {
            actual->setDato(value);
            return;
        }else {
            LLNode* siguiente = actual->getNext();
            actual = siguiente;
        }
    }
}

void ListaEnlazada::append(int value) {
    if (!cabeza) {
        cabeza = new LLNode(value);
        return;
    }

    // Si la lista no está vacía, recorre hasta el final
    LLNode* actual = cabeza;
    while (actual->getNext()) {
        actual = actual->getNext();  // Moverse al siguiente nodo
    }

    // Añadir el nuevo nodo al final de la lista
    actual->setNext(new LLNode(value));
}

void ListaEnlazada::deleteNode(int posicion) {
    if (posicion < 0 || !cabeza) {
        return;
    }

    // Caso especial: eliminar el primer nodo (posición 0)
    if (posicion == 0) {
        LLNode* temp = cabeza;
        cabeza = cabeza->getNext();
        delete temp;
        return;
    }

    // Recorrer la lista para encontrar el nodo en la posición dada
    LLNode* actual = cabeza;
    LLNode* anterior = nullptr;
    int contador = 0;

    while (actual && contador < posicion) {
        anterior = actual;
        actual = actual->getNext();
        contador++;
    }

    // Si la posición es mayor que el número de nodos en la lista
    if (!actual) {
        return;
    }

    anterior->setNext(actual->getNext());  // Conectar el nodo anterior con el siguiente nodo de actual
    delete actual;  // Eliminar el nodo actual
    actual = nullptr;  // Evitar un puntero colgante
}


