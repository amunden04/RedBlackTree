#ifndef TREE_H
#define TREE_H

enum colour {RED, BLACK, DOUBLEBLACK};

struct Node{
    int data;
    int colour;
    Node *left, *right, *parent;
    explicit Node(int);
};

class Tree{

    public:
        Tree();
        virtual ~Tree(){};
        void addValue(int);
        Node* insertNode(Node *, Node*);
        void deleteValue(int);
        void insertFix(Node *);
        void deleteFix(Node *);
        void leftRotation(Node *);
        void rightRotation(Node *);
        Node* findNode(int);
        Node* findNode(Node*, int);
        void findTest(int);
        void setColour(Node *, int);
        int getColour(Node *);
        void transplant(Node*, Node*);
        Node* successor(Node*);
        Node* findMin(Node*);
        Node* findMax(Node*);
        void walk();
        void print(Node*, int);

    private:
        Node* root;

};

#endif // TREE_H
