#include<stdio.h>

void swap(int* n1,int* n2){
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}
int partition(int * arr,int l,int h){
    int pivot=h;
    
    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr+i,arr+j);
        }
    }
    swap(arr+i+1,arr+pivot);
    return i+1;
}

void quick_sort(int* arr,int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);
    }
}
int main(){
    int a[7]={5,4,3,2,1,-1,-3};
    int size=7;
    quick_sort(a,0,size-1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(a+i));
    }
    
    return 0;
}