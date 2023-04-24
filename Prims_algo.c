
#include<stdio.h> 
#include<string.h>
#define V 5
int GRAPH[V][V] = {
  {0, 3, 0, 0, 5},
  {3, 0, 8, 5, 7},
  {0, 8, 0, 2, 0},
  {0, 5, 2, 0, 3},
  {5, 7, 0, 3, 0}};
 int  returnchar(int value){
    char a,b,c,d,e;
    switch(value){
        
case 0:return 'a';
break;
case 1:return 'b';
break;
case 2:return 'c';
break;
case 3:return 'd';
break;
case 4:return 'e';
break;
    }
  }

  int main(){
    int edge;
    int selectededge[V];
     memset(selectededge, -1, sizeof(selectededge));

    edge=0;
     selectededge[0]=1;
    int x,y;
int total_cost=0;

while(edge<V-1){
        int minimum=999999;
        x=0;y=0;
  for (int i = 0; i < V; i++) {

       if (selectededge[i]==1) {

        for (int j = 0; j < V; j++) {
            
          if (selectededge[j]!=1 && GRAPH[i][j]) {

            if (minimum > GRAPH[i][j]) {

              minimum = GRAPH[i][j];
              x = i;
              y = j;

            }
          }
        }
      }


    }
    total_cost+=minimum;
char inode=returnchar(x);
char dnode=returnchar(y);
    printf("%c - %c : %d\n", inode, dnode, GRAPH[x][y]);
    selectededge[y] = 1;
    edge++;

    }
    printf("\n Total cost is %d",total_cost);
    return 0;
  }