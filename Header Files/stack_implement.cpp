#include "Stack.h"
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