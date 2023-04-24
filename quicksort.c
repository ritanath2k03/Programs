#include<stdio.h>


int  partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
        
    }
    int t=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=t;
    return i+1;


}

void quick(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        quick(arr,low,p-1);
        quick(arr,p+1,high);
    }


}




int main()
{
    int i,n;
    printf("enter the no. of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the no.:");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quick(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;


}