#include<stdio.h>
class Node
{
private:
    int data;
    Node* next;
public:
    Node(int n,Node* nxt);
    ~Node();

    friend class Queue;
};

Node::Node(int n=0,Node* nxt=NULL)
{
    data=n;
    next=nxt;
}

Node::~Node()
{
}
class Queue
{
private:
    Node* head;
    int size;
    Node* tail;
public:
    Queue();
    ~Queue();
    void add(int n);
    int pop();
    int top();
    void print();
};
void Queue::add(int n){
    if(tail==NULL){
        head=new Node(n);
        tail=head;
        size++;
    }
    else{
        tail->next=new Node(n);
        tail=tail->next;
        size++;

    }
}
int Queue::pop(){
    Node* iter=head;
    if(head==tail && head!=NULL){
        head=NULL;
        tail=NULL;
        size--;
        int n=iter->data;
        delete iter;
        return n;

    }
    else if (iter!=NULL)
    {   
        int n=iter->data;
        head=head->next;
        size--;
        delete iter;
        return n;
    }

    return -1;
    
}

int Queue::top(){
    Node* iter=head;
    if (iter!=NULL)
    {   
        return iter->data;
    }
    return -1;
}

void Queue::print(){
    
    
    Node* iter=head;
    while(iter!=NULL){
        printf("%d ",iter->data);
        iter=iter->next;
    }
    printf("\nNumber of elements : %d\n\n\n",size);

}
Queue::Queue()
{
    head=NULL;
    size=0;
    tail=NULL;
}

Queue::~Queue()
{
}


int main(){
    Queue s;
    s.add(3);
    s.print();
    s.add(1);
    s.print();
    s.add(2);
    s.print();
    s.add(5);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.add(5);
    s.print();
    return 0;
}