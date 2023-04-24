#include<stdio.h>
int mainarray[6]={4,10,3,12,20,7};
int minArray[5][5];


void min(int n,int i,int j){
    
    if(minArray[i][j]>n){
        minArray[i][j]=n;
    }
}


void findmin(int i,int j){
     

    minArray[i][j]=9999999;
for(int k=i;k<=j-1;k++){
   int q=(minArray[i][k]+minArray[k+1][j]+(mainarray[i-1]*mainarray[k]*mainarray[j]));
min(q,i,j);
}
}


int main(){
    for (int i = 1; i < 6; i++)
      minArray[i][i] = 0;
for(int l=2;l<6;l++){
 for(int i=1;i<6-l+1;i++){//0 1 2 3 4 5 6
 int j=l+i-1;
    findmin(i,(j));//0 1 1 2 2 3 3 4
 }
}

   printf("min is %d",minArray[1][5]); 

}

/*#include <stdio.h>
int Multuplication(int arr[], int n) {
   int min[n][n];
   int j, q;
   for (int i = 1; i < n; i++)
      min[i][i] = 0;
   for (int L = 2; L < n; L++) {
      for (int i = 1; i < n - L + 1; i++) {
         j = i + L - 1;
         min[i][j] = 99999999;
         for (int k = i; k <= j - 1; k++) {
            q = min[i][k] + min[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
            if (q < min[i][j])
            min[i][j] = q;
         }
      }
   }
   
   return min[1][n - 1];
}
int main(){
   int p[] = {4,10,3,12,20,7};
   int size = sizeof(p) / sizeof(p[0]);
   printf("Minimum number of multiplications required for the matrices multiplication is %d ",    Multuplication(p,size));
   return 0;
}*/