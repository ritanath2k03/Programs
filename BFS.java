import java.util.LinkedList;
import java.util.Scanner;
public class BFS {
 LinkedList queue=new LinkedList<Integer>() ;
//this is the graph initialization
//by adjacency matrix
public int[][] Graph={{0,1,0,1,0,0,0},
                 {0,0,1,0,0,0,0},
                 {0,0,0,0,1,0,1},
                 {0,0,0,0,0,1,0},
                 {0,1,0,0,0,1,0},
                 {1,0,0,0,0,0,0},
                 {0,0,0,0,1,0,0}};
public int[] visited={0,0,0,0,0,0,0};
    public static void main(String[] args) {
      
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the starting node in between 0 to 6 \n");
        int start=sc.nextInt();
         //To access the data or method in a class we r defining a object
        BFS bfs=new BFS();
            System.out.print(start+"-->");
            bfs.visited[start]=1;
            bfs.queue.add(start);
            while(!bfs.queue.isEmpty()){
int  node=(int)bfs.queue.remove();
for(int j=0;j<7;j++){
    if(bfs.Graph[node][j]==1 && bfs.visited[j]==0){
        System.out.print(j+"-->");
        bfs.visited[j]=1;
        bfs.queue.add(j);
    }
  }
}
System.out.println("NULL");
}
}

