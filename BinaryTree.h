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
    Node* insert(Node* node, int key);
    void inorder(Node* root);

    Node *search(Node *root, int key);
};


#endif //BINARYTREE_H
