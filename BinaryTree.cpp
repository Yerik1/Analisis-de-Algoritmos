//
// Created by yerik on 9/15/24.
//
#include "BinaryTree.h"


Node* BinarySearchTree::insert(Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == nullptr)
        return new Node(key);

    // If the key is already present in the tree,
    // return the node
    if (node->key == key)
        return node;

    // Otherwise, recur down the tree/ If the key
    // to be inserted is greater than the node's key,
    // insert it in the right subtree
    if (node->key < key)
        node->right = insert(node->right, key);

    // If the key to be inserted is smaller than
    // the node's key,insert it in the left subtree
    else
        node->left = insert(node->left, key);

    // Return the (unchanged) node pointer
    return node;
}

void BinarySearchTree::inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
Node* BinarySearchTree::search(Node* root, int key) {
    // Caso base: si el árbol está vacío o el valor está en la raíz
    if (root == nullptr || root->key == key)
        return root;

    // Si el valor es mayor que la clave de la raíz, buscar en el subárbol derecho
    if (root->key < key)
        return search(root->right, key);

    // Si el valor es menor que la clave de la raíz, buscar en el subárbol izquierdo
    return search(root->left, key);
}