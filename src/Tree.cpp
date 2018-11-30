#include "Tree.h"
#include <bits/stdc++.h>

using namespace std;

Node::Node(int data) {
    this->data = data;
    colour = RED;
    left = right = parent = nullptr;
}

Tree::Tree() {
    root = nullptr;
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
    Node* parent = nullptr;
    Node* grandparent = nullptr;
    while(node != root && getColour(node) == RED && getColour(node->parent) == RED)
    {
        parent = node->parent;
        grandparent = parent->parent;
        if(parent == grandparent->left){
            Node* uncle = grandparent->right;
            if(getColour(uncle) == RED)
            {
            setColour(uncle, BLACK);
            setColour(parent, BLACK);
            setColour(grandparent, RED);
            node = grandparent;
            } else {
                if(node == parent->right){
                node = parent;
                leftRotation(parent);
                parent = node->parent;
            }
            rightRotation(grandparent);
            swap(parent->colour, grandparent->colour);
            node = parent;
            }
        } else {
             Node* uncle = grandparent->left;
            if(getColour(uncle) == RED)
            {
                setColour(uncle, BLACK);
                setColour(parent, BLACK);
                setColour(grandparent, RED);
                node = grandparent;
            } else {
            if(node == parent->left){
                 node = parent;
                rightRotation(parent);
                parent = node->parent;
            }
            leftRotation(grandparent);
            swap(parent->colour, grandparent->colour);
            node = parent;
        }
    }
        }
    setColour(root, BLACK);
}

void Tree::leftRotation(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if(x->right != nullptr)
        x->right->parent = x;
    y->parent = x->parent;

    if(x->parent == nullptr)
       root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void Tree::rightRotation(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if(x->left != nullptr)
        x->left->parent = x;
    y->parent = x->parent;

    if(x->parent == nullptr)
       root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}

Node* Tree::findNode(Node *x,int k) {
  // base case
  if(x->data == k)
    return x;

  if(k<x->data)
    return findNode(x->left,k);
  else
    return findNode(x->right,k);
}

void Tree::findTest(int k) {
  Node *x = findNode(root,k);
  cout << "Node found is: " << x->data << " Left child is: " << x->left->data /*<< " Right child is: " << x->right->data*/;
}

void Tree::transplant(Node* u, Node* v) {
  if(u->parent == nullptr)
    root = v;
  else if(u==u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  v->parent = u->parent;
}

Node* Tree::successor(Node *x){
  if(x->right != nullptr)
    return findMin(x->right);
  Node *y = x->parent;
  while(y != nullptr) {
    x = y;
    y = y->parent;
  }
  return y;
}

Node* Tree::findMin(Node *x) {
  while (x->left!=nullptr)
    x = x->left;
  return x;
}

Node* Tree::findMax(Node *x) {
  while (x->right!=nullptr)
    x = x->right;
  return x;
}

void Tree::deleteValue(Node* node){


}

void Tree::deleteFix(Node* node) {


}

void Tree::walk() {
  print(root,1);
}

void Tree::print(Node *x, int space)
{
    // Base case
    if (x == nullptr)
        return;
    int COUNT = 1;
    if(COUNT == -1)
      COUNT = 1;
    space += COUNT;

    // Process right child first
    print(x->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << "   ";
    cout << x->data << "(" << x->colour << ")" << endl;

    // Process left child
    print(x->left, space);

}
