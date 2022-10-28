#include<stdio.h>
class Node
{
private:
    int data;
    Node* next;
public:
    Node(int n);
    Node();
    ~Node();
    friend class Linked_list;
};

Node::Node(int n)
{   
    data=n;
    next=NULL;
}
Node::Node()
{   
    data=0;
    next=NULL;
}

Node::~Node()
{
}

class Linked_list
{
private:
    Node* head;
    int size;
public:
    Linked_list();
    ~Linked_list();
};

Linked_list::Linked_list()
{
    head=NULL;
}

Linked_list::~Linked_list()
{
    while(head!=NULL){
        Node* iter=head;
        head=head->next;
        delete iter;
    }
}
