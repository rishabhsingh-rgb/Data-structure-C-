#include<stdio.h>

int binary_search(int arr[],int item,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
        {
            return mid;
        }
        else if(item<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}

void main()
{
    int arr[]={2,5,6,7,8,9,34,67};
    int size=sizeof(arr)/sizeof(arr[0]);
    int low=0,high=size-1;
    int item;
    printf("Enter item to search:- ");
    scanf("%d",&item);
    int index=binary_search(arr,item,low,high);
    if(index!=-1)
    {
        printf("%d found at %d index.\n",item,index);
    }
    else
    {
        printf("Element not found.\n");
    }
}
