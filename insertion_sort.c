#include<stdio.h>

 void insertion_sort(int arr[],int size)
 {
    for(int i=1;i<size;i++)
    {
      int key=arr[i];  
      int j=i-1;
      while(j>=0 && arr[j]>key)
      {
          arr[j+1]=arr[j];
          j-=1;
      }
      arr[j+1]=key;
    }
 }
 void main()
 {
    int arr[]={2,54,3,45,78,98,33};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,size);

    printf("Sorted array:-\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
 }
