#include<stdio.h>
#define ERR -1
class Node
{
private:
    int data;
    Node* next;
public:
    Node(int n,Node* nxt);
    ~Node();
    friend class Linked_list;
};

Node::Node(int n=0,Node* nxt=NULL){
    data=n;
    next=nxt;
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
    void print();
    void addFront(int n);
    void addBack(int n);
    void removeFront();
    void removeBack();
    int operator [] (int idx);

};

Linked_list::Linked_list()
{
    head=NULL;
    size=0;
}

Linked_list::~Linked_list()
{
    while(head!=NULL){
        Node* iter=head;
        head=head->next;
        delete iter;
    }
}

void Linked_list::print(){
    int count=0;
    Node* iter=head;
    while (iter!=NULL)      
    {
        printf("%d ",iter->data);
        count++;
        iter=iter->next;
    }
    
    printf("\nTotal elements: %d\n",count);
}
int Linked_list::operator [] (int idx){
    if(head==NULL){
        return ERR;
    }
    int count=0;
    Node* iter=head;
    while (iter!=NULL && count<idx-1)      
    {
        iter=iter->next;
        count++;
    }
    
    return iter->data;
}
void Linked_list::addFront(int n){
    head=new Node(n,head);
    size++;
}
void Linked_list::addBack(int n){
    if(head==NULL){
        head=new Node(n);
        return;
    }
    Node* iter=head;
    while (iter->next!=NULL)
    {
        iter=iter->next;
    }
    iter->next=new Node(n);
    size++;
    
}

void Linked_list::removeFront(){
    if (head==NULL)
    {
        return;
    }
    
    Node* iter=head;
    head=head->next;
    delete iter;
    size--;
}
void Linked_list::removeBack(){
    Node* iter=head;
    if(iter==NULL)return;
    if(iter->next==NULL){
        delete iter;
        head=NULL;
        return;
    }
    while (iter->next->next!=NULL)
    {
        iter=iter->next;
    }
    delete iter->next;
    iter->next=NULL;
    
}

int main(){
    Linked_list L;

    L.addFront(2);
    L.addFront(2);
    L.addFront(2);
    L.addFront(2);
    L.addFront(2);
    L.addFront(2);
    L.addBack(3);
    L.print();   
    L.addBack(5);
    L.print();   
    L.removeBack();
    L.print();
    L.removeFront();
    L.print();
    printf("%d",L[6]);
    return 0;
}