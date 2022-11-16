#include<stdio.h>
void swap(int* n1,int* n2){
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}

int partitionr(int * arr,int l,int h){
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

int k_largest(int* arr,int l,int h,int k){
    int pi=partitionr(arr,l,h);

    // printf("\n%d\n",pi);
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%d ",*(arr+i));
    // }
    if(h-pi+1==k){
        return arr[pi];
    }
    else if(h-pi+1>k){
        return k_largest(arr,pi+1,h,k);
    }
    else
        return k_largest(arr,l,pi-1,k-h+pi-1);
}
int main(){
    int a[7]={5,4,3,1,1,-1,-3};
    int size=7;
    printf("%d\n",k_largest(a,0,6,7));
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ",*(a+i));
    // }
    return 0;
}