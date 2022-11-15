#include<stdio.h>
void merge(int* arr,int l,int mid,int h){
    const int n1=mid-l+1,n2=h-mid;
    int arrleft[n1];
    int arrright[n2];


    for (int i = 0; i < n1; i++){
        arrleft[i]=arr[l+i];
    }
    for (int i = 0; i < n1; i++){
        arrright[i]=arr[ mid+1+i];
    }

    int j=0,k=l,i=0;
    while (i<n1 && j<n2){
        if(arrleft[i]<=arrright[j] ){
            arr[k]=arrleft[i];
            i++;k++;
        }
        else{
            arr[k]=arrright[j];
            j++;k++;
        }
    }

    while (i<n1){
        arr[k]=arrleft[i];
        i++;k++;
    }
    while (j<n2){
        arr[k]=arrright[j];
        j++;k++;
    }
    
}


void mergesort(int* arr,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);

    }
}

int main(){
    int a[7]={2,2,3,3,3,4,5};
    int size=7;
    mergesort(a,0,size-1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(a+i));
    }
    
    return 0;
}