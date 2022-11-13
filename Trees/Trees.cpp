#include<stdio.h>
class Node
{
private:
public:
    int data;
    Node* left;
    Node* right;
    Node(int n,Node* lft,Node* rgt);
    ~Node();
    friend class Tree;
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
public:
    Node* root;
    Tree();
    ~Tree();
    void insert(Node* root,int n);
    void Inorder(Node* root);
};

Tree::Tree()
{
    root=NULL;
}

Tree::~Tree()
{
}


void Tree::insert(Node* rot,int n){
    if(root==NULL){
        root=new Node(n);
        return;
    }
    else{
        Node* iter=rot;
        if(n<iter->data){
            if(iter->left==NULL){
                iter->left=new Node(n);
                return;
            }
            insert(iter->left,n);
        }
        else if (n>iter->data)
        {   
            if(iter->right==NULL){
                iter->right=new Node(n);
                return;
            }
            insert(iter->right,n);
        }
        
    }
}


void Tree::Inorder(Node* rot)
{   
    // printf("Hello");
    if (!rot) {
        return;
    }
    Inorder(rot->left);
    printf("%d ",rot->data);
    // cout << root->data << endl;
    Inorder(rot->right);
}
int main(){
    Tree t;
    t.insert(t.root,2);
    t.insert(t.root,10);
    t.insert(t.root,3);
    t.insert(t.root,1);
    t.insert(t.root,17);
    t.insert(t.root,13);
    t.insert(t.root,35);
    // printf("%d \n",(t.root->left)->data);
    t.Inorder(t.root);
    return 0;
}