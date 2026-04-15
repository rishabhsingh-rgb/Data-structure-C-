#include<stdio.h>

void bubble_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void main()
{
    int arr[]={22,45,3,45,67,54,24};
    int size=sizeof(arr)/sizeof(arr[0]);
    //call by reference
    bubble_sort(arr,size);
    printf("Sorted array:-\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
