#include<stdio.h>

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j;
    for(j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}

void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}

void main()
{
    int arr[]={45,43,2,47,85,33};
    int size=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size-1);

    printf("After sorting:-\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
