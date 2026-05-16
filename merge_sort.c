#include<stdio.h>

void merge(int arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int temp[100];
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
            temp[k]=arr[j];
            j++;
        }
        else
        {
            temp[k]=arr[i];
            i++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=high)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else if(j>high)
    {
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int x=low;x<=high;x++)
    {
        arr[x]=temp[x];
    }
}

void merge_sort(int arr[],int low,int high)
{
    int mid=(low+high)/2;
    if(low<high)
    {
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void main()
{
    int arr[]={2,5,34,4,67,42,12,35};
    int size=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,size-1);
    printf("Sorted array:-\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
