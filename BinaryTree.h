//
// Created by yerik on 9/15/24.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree {
public:
    // A utility function to insert a new node with
    // the given key
    Node* insert(Node* node, int key);
    // A utility function to do inorder tree traversal
    void inorder(Node* root);

    Node *search(Node *root, int key);
};


#endif //BINARYTREE_H
