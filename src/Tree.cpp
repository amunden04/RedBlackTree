#include "Tree.h"
#include <bits/stdc++.h>

using namespace std;

Node::Node(int data) {
    this->data = data;
    colour = RED;
    left = right = parent = nullptr;
}

int Tree::getColour(Node* node) {
    if (node == nullptr)
        return BLACK;
    return node->colour;
}

void Tree::setColour(Node* node, int colour) {
    if(node == nullptr)
        return;
    node ->colour = colour;
}

void Tree::addValue(int n) {
    Node *node = new Node(n);
    root = insertNode(root, node);
    insertFix(node);
}

Node* Tree::insertNode(Node* root, Node* node) {
    if(root == nullptr)
        return node;

    if(node->data < root->data){
        root->left = insertNode(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = insertNode(root->right, node);
        root->right->parent = root;
    }
    return root;
}

void Tree::insertFix(Node* node) {


}

void Tree::leftRotation(Node* node) {


}

void Tree::rightRotation(Node* node) {


}

void Tree::displayTree() {
    cout << root->data << " " << root->colour << endl;
    cout << root->left->data << " " << root->left->colour << " "
         << root->right->data << " " << root->right->colour << endl;
}
