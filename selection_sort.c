#include<stdio.h>

void selection_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void main()
{
    int arr[]={22,45,3,45,67,54,24};
    int size=sizeof(arr)/sizeof(arr[0]);
    //call by reference
    selection_sort(arr,size);
    printf("Sorted array:-\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
