#include<stdio.h>
class Node
{
private:
    int data;
    Node* left;
    Node* right;
public:
    Node(int n,Node* lft,Node* rgt);
    ~Node();
};

Node::Node(int n=0,Node* lft=NULL,Node* rgt=NULL)
{
    data=n;
    left=lft;
    right=rgt;

}

Node::~Node()
{
}

class Tree
{
private:
    Node* root;
public:
    Tree(Node* rot=NULL);
    ~Tree();
};

Tree::Tree(Node* rot=NULL)
{
    root=rot;
    
}

Tree::~Tree()
{
}

