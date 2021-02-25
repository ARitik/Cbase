#include<stdio.h>

#define V 5
#define INFINITY 9999

void dijkstra(int graph[V][V],int distance[V],int visited[V]) {
	int visitctr=0;
	int iter=0;
	while(visitctr!=5) {
		int min = 9999;
		int mindex = -1;
		if(visited[iter]==-1) {
			visitctr++;
			visited[iter]=1;
			for(int i=0;i<V;i++) {
				if(graph[iter][i]!=0 && (graph[iter][i]+distance[iter])<distance[i]) {
					distance[i] = graph[iter][i] + distance[iter];
					if(graph[iter][i] < min) {
						min = graph[iter][i];
						mindex = i;
					}
				}
			}
		}
		if(min!=9999)
			iter=mindex;
		else
			iter=(iter+1)%V;
	}
	for(int i=0;i<V;i++)
		printf("\nShortest Path from 0 to %d is:\t %d",i,distance[i]);
}

int main() 
{ 
    int graph[V][V] = {{0,4,2,0,0},{0,0,3,2,3},{0,1,0,4,5},{0,0,0,0,0,},{0,0,0,1,0}}; 
  	int visited[V],distance[V];
  	for(int i=0;i<V;i++) {
  		visited[i] = -1;
  		distance[i] = INFINITY; 
  	}
  	distance[0] = 0; // 0 is the Source Vertex
  	
    dijkstra(graph,distance,visited); 
  
    return 0; 
}

