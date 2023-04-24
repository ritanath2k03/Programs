#include <stdio.h>
#include<stdlib.h>
int array[10];
// void sorted(int array[],int n){
//     int i,j;
//     for(i=0;i<=n-1;i++){
//         for(j=1;j<=n;j++){
//             if(array[i]>array[j]){    //3 7 2 5 1 //1 2 3 5 7
//                 int temp=array[i];//3
//                 array[i]=array[j];//7
//                 array[j]=temp;//3
//             }
//         }
//     }
// }

int binarySearch(int array[], int x, int low, int high) {
 // Repeat until the pointers low and high meet each other
//  int array[10]=sorted(array,high);
 while (low <= high) {
   int mid = low + (high - low) / 2;

   if (array[mid] == x)
     return mid;

   if (array[mid] < x)
     low = mid + 1;

   else
     high = mid - 1;
 }

 return -1;
}

int main() {
	int n,i;
	scanf("%d",&n);
 int arr[n];
 
 for(i=0;i<n;i++)
 scanf("%d",&arr[i]);
 int x;
 scanf("%d",&x);
 int result = binarySearch(arr, x, 0, n - 1 );
 if (result == -1)
   printf("Not found");
 else
   printf("Element is found at index %d", result);
 return 0;
}