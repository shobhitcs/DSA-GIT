#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
int partitionl(int * arr,int l,int h){
    int pivot=l;
    
    int i=h+1;
    for(int j=h;j>l;j--){
        if(arr[j]>arr[pivot]){
            i--;
            swap(arr+i,arr+j);
        }
    }
    swap(arr+i-1,arr+pivot);
    return i-1;
}

void quick_sort(int* arr,int l,int h){
    if(l<h){
        int p=partitionl(arr,l,h);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);
    }
}



class List
{
	int*list;
	int listSize;
	class List*nextList;

	public:
	void reset()
	{
		nextList=NULL;
		list=NULL;
	}
	void initList(int size,int*list)
	{
		listSize=size;
		this->list=list;
	}
	void attachList(List*ptr)
	{
		this->nextList=ptr;
	}
	int getSize(){return listSize;}//returns the size of the list

	int getDataAtIndex(int index)//returns the data at a given index
	{
		return list[index];
	}
	List*getNext()//returns the pointer to the next list
	{
		return nextList;
	}
};

List*begin=NULL,*prev=NULL,*current=NULL;


void printList(List*current)//prints the list contents pointed by current
{
	int j=0;
	do
	{
		printf("%d ",current->getDataAtIndex(j));
		j++;
	}while(j!=current->getSize());
	printf("\n");
}

int main()
{
	FILE*fp1;
	FILE*fp2;
	int listCount;	
	int listSize;
	int*templist;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	fscanf(fp1,"%d",&listCount);
//	printf("%d",listCount);
	
	for(int i=0;i<listCount;i++)
	{
		current=(class List*)malloc(sizeof(class List));
		current->reset();
		fscanf(fp1,"%d",&listSize);

		int*tempList=(int*)calloc(listSize,sizeof(int));
		for(int j=0;j<listSize;j++)
		{
			fscanf(fp1,"%d",&tempList[j]);
			
		}
		quick_sort(tempList,0,listSize-1);
		current->initList(listSize,tempList);
		if(begin==NULL)
		{
			begin=current;
		}
		else
		{
			prev->attachList(current);
		}
		prev=current;
	}

	current=begin;
	printf("\n");
	do
	{
		printList(current);
		current=current->getNext();
	}while(current!=NULL);

	// quick_sort(begin->,0,begin->getSize()-1);
    // for (int i = 0; i < size; i++)
    // {
    //     // printf("%d ",*(a+i));
    // }
	fclose(fp1);
	fclose(fp2);

}

