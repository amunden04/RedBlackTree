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
  if (root == nullptr)
    return node;

  if(node->data < root->data) {
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
  while(node != root && getColour(node) == RED && getColour(node->parent) == RED) {
    parent = node->parent;
    grandparent = parent->parent;
    if(parent == grandparent->left) {
      Node* uncle = grandparent->right;
      if(getColour(uncle) == RED) {
        setColour(uncle, BLACK);
        setColour(parent, BLACK);
        setColour(grandparent, RED);
        node = grandparent;
      } else {
        if(node == parent->right) {
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
      if(getColour(uncle) == RED) {
        setColour(uncle, BLACK);
        setColour(parent, BLACK);
        setColour(grandparent, RED);
        node = grandparent;
      } else {
        if(node == parent->left) {
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

Node* Tree::findNode(int k) {
  return findNode(root,k);
}

Node* Tree::findNode(Node* x, int k) {
  if(x->data == k)
    return x;
  if (k < x->data) {
    if(x->left == nullptr)
      return nullptr;
    return findNode(x->left, k);
  } else {
    if(x->right == nullptr)
      return nullptr;
    return findNode(x->right, k);
  }
}

void Tree::findTest(int k) {
  Node *x = findNode(root,k);
  //cout << "Node found is: " << x->data << " Left child is: " << x->left->data
      // << " Right child is: " << x->right->data;
}

void Tree::transplant(Node* u, Node* v) {
  if(u==u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
}

Node* Tree::successor(Node *x) {
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

void Tree::deleteValue(int k) {
  Node* x = findNode(k);
  Node* y = nullptr;
  if(x == nullptr){
    x = nullptr;
  }else {
  if(x->right == nullptr)
    y = x;
  else {
    y = findMin(x->right);
    x->data = y->data;
  }
  deleteFix(y);
}
}

void Tree::deleteFix(Node* x) {
    //Test if delete was called on a non-existing key
  if (x == nullptr)
    return;

    //Test if x is root
  if (x == root) {
    root = nullptr;
    return;
  }

  if (getColour(x) == RED || getColour(x->left) == RED || getColour(x->right) == RED) {
    Node* child = nullptr;
    if(x->left != nullptr) {
      child = x->left;
    } else {
      child = x->right;
    }
    transplant(x, child);
    setColour(child, BLACK);
    delete (x);
  } else {
    Node* sibling = nullptr;
    Node* parent = nullptr;
    Node* y = x;
    setColour(y, DOUBLEBLACK);

    //While x is not the root and is still DOUBLEBLACK
    while(y != root && getColour(y) == DOUBLEBLACK) {
      parent = y->parent;
      if(y == parent->left) {
        sibling = parent->right;
        //Case 1 - can only result in cases 2,3, or 4
        if(getColour(sibling) == RED) {
          setColour(sibling, BLACK);
          setColour(parent, RED);
          leftRotation(parent);
        } else { //Everything in this else is either case 2, 3, or 4
          //Case 2 - solves DOUBLEBLACK and so while loop won't execute afer case 2
          if(getColour(sibling->left) == BLACK && getColour(sibling->right) == BLACK) {
            setColour(sibling, RED);
            if (getColour(parent) == RED)
              setColour(parent, BLACK);
            else
              setColour(parent, DOUBLEBLACK);
            y = parent;
            //else either case 3 or case 4 apply
          } else {
            //Case 3 applies -- always results in case 4
            if(getColour(sibling->right) == BLACK) {
              setColour(sibling->left, BLACK);
              setColour(sibling, RED);
              rightRotation(sibling);
              sibling = parent->right;
            }
            setColour(sibling, getColour(parent));
            setColour(parent, BLACK);
            setColour(sibling->right, BLACK);
            leftRotation(parent);
            break;
          }
        }
      } else {
        // Symmetrical to first 4 cases
        sibling = parent->left;
        // Case 1
        if(getColour(sibling) == RED) {
          setColour(sibling, BLACK);
          setColour(parent, RED);
          rightRotation(parent);
        } else {
          // Case 2
          if(getColour(sibling->left) == BLACK && getColour(sibling->right) == BLACK) {
            setColour(sibling, RED);
            if (getColour(parent) == RED)
              setColour(parent, BLACK);
            else
              setColour(parent, DOUBLEBLACK);
            y = parent;
          } else {
            // Case 3
            if(getColour(sibling->left) == BLACK) {
              setColour(sibling->right, BLACK);
              setColour(sibling, RED);
              leftRotation(sibling);
              sibling = parent->left;
            }
            setColour(sibling, getColour(parent));
            setColour(parent, BLACK);
            setColour(sibling->left, BLACK);
            rightRotation(parent);
            break;
          }
        }
      }
    }
    if(y == x->parent->left)
      x->parent->left = nullptr;
    else
      x->parent->right = nullptr;
    delete (x);

    setColour(root, BLACK);
  }
}

void Tree::walk() {
  print(root,1);
}

void Tree::print(Node *x, int space) {
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
