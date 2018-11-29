#ifndef TREE_H
#define TREE_H

enum colour {RED, BLACK, DOUBLEBLACK};

struct Node{
    int data;
    int colour;
    Node *left, *right, *parent;
    explicit Node(int);
};

class Tree
{
    public:
        Tree(){root = nullptr;};
        virtual ~Tree();
        void insertValue(int);
        void deleteValue(int);
        void insertFix(Node *);
        void deleteFix(Node *);
        void leftRotation(Node *);
        void rightRotation(Node *);
        void findNode();
        void setColour(Node *, int);
        int getColour(Node *);

    protected:

    private:
        Node *root;
};

#endif // TREE_H
