#include<stdio.h>
#include "Stack.h"
int match_brackets(char* a);
int isopen(char ch){
    char open[]="({[";
    for(int i=0;i<3;i++){
        if(ch==open[i])
        return 1;
    }
    return 0;
}
int isclose(char ch){
    char close[]=")}]";
    for(int i=0;i<3;i++){
        if(ch==close[i])
        return i;
    }
    return -1;
}
int main(){
    char s[]="{}({([])})[]";
    printf("%d ",match_brackets(s));

    return 0;
}
int match_brackets(char* a){
    Stack st;
    char open[]="({[";
    char close[]=")}]";
    for(int i=0;a[i]!=0;i++){
            // printf("7");
        if(isopen(a[i])==1){
            st.add(int(a[i]));
            // printf("1");
           
        }
        else if(isclose(a[i])>-1){
            if(st.top()==-1){
            // printf("9");
                return 0;
            }
            else if(st.top()==open[isclose(a[i])]){
            // printf("3");
                st.pop();
            }
            else {
                
            // printf("%c",st.top());
            // printf("%c",a[i]);
            // printf("\nHello");
            // st.print();

                return 0;}
        }
    }
    if(st.top()!=-1){
            // printf("5");
        return 0;
    }
    else return 1;

}