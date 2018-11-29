#include "Tree.h"
#include <iostream>

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
