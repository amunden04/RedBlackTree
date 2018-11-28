#include "Tree.h"
#include <iostream>

using namespace std;

Node::Node(int data) {
    this->data = data;
    colour = RED;
    left = right = parent = nullptr;
}

Tree::Tree() {
    root = nullptr;
}
