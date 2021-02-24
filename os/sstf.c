#include<stdio.h>

int computeMin(int arr[],int visited[],int diff,int s) {
    int min = 9999,mdex=0;
    for(int j=0;j<s;j++) {
        int d = arr[j] - diff;
        if(d<0)
            d*=(-1);
        if(d<min && visited[j]==0) {
            min = d;
            mdex = j;
        }
    }
    return mdex;
}

int main() {
    int n;
    printf("\nEnter number of tracks");
    scanf("%d",&n);
    int tracks[n],visited[n],sp;
    printf("\nEnter track data");
    for(int i=0;i<n;i++) {
        scanf("%d",&tracks[i]);
        visited[i] = 0;
    }
    float avg = 0;
    printf("\nEnter Start Position");
    scanf("%d",&sp);
    int x = sp;
    printf("\nTraversed\tDifference");
    for(int i=0;i<n;i++) {
        int y = x;
        x = computeMin(tracks,visited,x,n);
        visited[x] = 1;
        int diff = tracks[x]-y;
        if(diff < 0)
            diff*=(-1);            
        printf("\n%d\t%d",tracks[x],diff);
        avg+=diff;
        x=tracks[x];
    }
    printf("\nAvg Header movement %f",avg/n);

}