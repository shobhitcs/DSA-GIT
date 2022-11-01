#include<stdio.h>
class Node
{
private:
    int data;
    Node* next;
public:
    Node(int n,Node* nxt);
    ~Node();

    friend class Stack;
};

Node::Node(int n=0,Node* nxt=NULL)
{
    data=n;
    next=nxt;
}

Node::~Node()
{
}
class Stack
{
private:
    Node* head;
    int size;
public:
    Stack();
    ~Stack();
    void add(int n);
    int pop();
    int top();
    void print();
};
void Stack::add(int n){
    head=new Node(n,head);
    size++;
}
int Stack::pop(){
    Node* iter=head;
    if (iter!=NULL)
    {   
        int n=iter->data;
        head=head->next;
        size--;
        delete iter;
        return n;
    }
    return -1;
    
}

int Stack::top(){
    Node* iter=head;
    if (iter!=NULL)
    {   
        return iter->data;
    }
    return -1;
}

void Stack::print(){
    Node* iter=head;
    while(iter!=NULL){
        printf("%d ",iter->data);
        iter=iter->next;
    }
    printf("\n");

}
Stack::Stack()
{
    head=NULL;
    size=0;
}

Stack::~Stack()
{
}


int main(){
    Stack s;
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
    return 0;
}