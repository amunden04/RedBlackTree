#ifndef TREE_H
#define TREE_H

enum colour {RED, BLACK, DOUBLEBLACK};

struct {
    int data;
    int colour;
    Node *left, *right, *parent;
};

class Tree
{
    public:
        Tree();
        virtual ~Tree();
        void insertValue(int);
        void deleteValue(int);
        void findNode();

    protected:

    private:
        Node *root;
};

#endif // TREE_H
