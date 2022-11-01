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
    void removeDuplicate();
    void mid();
    Linked_list add(Linked_list& l);

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
        // printf("%u  %u",iter,head);
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
    if(head==NULL || size<idx){
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
        size++;
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
        size--;
        return;
    }
    while (iter->next->next!=NULL)
    {
        iter=iter->next;
    }
    delete iter->next;
    iter->next=NULL;
    size--;
    
}
void Linked_list::removeDuplicate(){
    Node* iter=head;
    if(iter==NULL || iter->next==NULL)
        return;
    
    while (iter!=NULL){
        Node* check=iter;
        int n=iter->data;
        iter=iter->next;
        while (iter!=NULL && iter->data==n)
        {
            Node* buf=iter;
            iter=iter->next;
            delete buf;
            size--;
        }
        check->next=iter;
    }
    
}

void Linked_list::mid(){
    if((size^1)==size){
        printf("Middle elements: %d and %d\n",(*this)[size/2],(*this)[size/2+1]);
    }
    else{
        printf("Middle elements: %d \n",(*this)[size/2+1]);

    }
}
Linked_list Linked_list::add(Linked_list& l){
    int n1=0,n2=0;
    Node* iter=head;
    while (iter!=NULL)
    {
        n1=n1*10+(iter->data);
        iter=iter->next;
    }
    iter=l.head;
    while (iter!=NULL)
    {
        n2=n2*10+(iter->data);
        iter=iter->next;
    }
    int n=n1+n2;
    // printf("%d\n",n);
    Linked_list lptr;
    while(n>0){
        lptr.addFront(n%10);
        n/=10;
    // printf("%d\n",n);
    }
    // lptr.print();
    return lptr;

    
}
int main(){
    // Linked_list L;

    // L.addFront(2);
    // L.addFront(2);
    // L.addFront(2);
    // L.addFront(2);
    // L.addFront(2);
    // L.addFront(2);
    // L.addBack(3);
    // L.addBack(3);
    // L.addBack(3);
    // L.addBack(3);
    // L.addBack(3);
    // L.addBack(7);
    // L.addBack(8);
    // L.addBack(5);
    // L.addBack(5);
    // L.print();   
    // L.addBack(5);
    // L.print();   
    // L.removeBack();
    // L.print();
    // L.removeFront();
    // L.print();
    // printf("%d\n",L[15]);
    // L.removeDuplicate();
    // L.print();
    // L.mid();
    Linked_list l1,l2;
    l1.addFront(1);
    l1.addFront(2);
    l1.addFront(1);
    // l2.addFront(2);
    l2.addFront(3);
    // l3.print();
    Linked_list l3=l1.add(l2);
// 
    // printf("Middle\n");
    l3.print();
    // printf("hello\n");
    return 0;
}