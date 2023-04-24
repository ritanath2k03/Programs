#include<stdio.h>
int array [100];
int min=10000,max=0;
int divide(int low,int high){
    if(low>high)
    return 0;
    int mid=low+(high-low)/2;
    min=check_min(mid);
    max=check_max(mid);
    divide(low,mid-1);
    divide(mid+1,high);

}
int check_max(int index){
    if(array[index]>max)
    return array[index];
    return max;
}
int check_min(int index){
    if(array[index]<min)
    return array[index];
    return min;
}
int main(){
       int n;
    printf("Enter number of elements");
    scanf("%d",&n);
    printf("Enter the array elements");
    int i,j;
    array[n];
    for(i=0;i<n;i++){
    scanf("%d",&array[i]);
    }
    divide(0,n-1);
    printf("minimum value is %d \n max value is %d",min,max);
    return 0;
    
}