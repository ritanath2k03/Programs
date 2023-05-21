#include<stdio.h>

int GRAPH [7][7]={{0,1,0,1,0,0,0},
                 {0,0,1,0,0,0,0},
                 {0,0,0,0,1,0,1},
                 {0,0,0,0,0,1,0},
                 {0,1,0,0,0,1,0},
                 {1,0,0,0,0,0,0},
                 {0,0,0,0,1,0,0}};
 int visited[7]={0,0,0,0,0,0,0};
 int DFS(int start){
    printf("%d ",start);
    visited[start]=1;
    for(int i=0;i<7;i++){
        if(GRAPH[start][i]==1 && visited[i]==0){
            DFS(i);
    }
 }
 }

int main(){

    DFS(0);
return 0;
}