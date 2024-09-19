//
// Created by yerik on 9/15/24.
//
#include "BinaryTree.h"


Node* BinarySearchTree::insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (node->key == key)
        return node;

    if (node->key < key)
        node->right = insert(node->right, key);

    else
        node->left = insert(node->left, key);

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
    if (root == nullptr || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}