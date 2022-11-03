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