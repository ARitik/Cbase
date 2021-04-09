#include<stdio.h>
#include<stdlib.h>

void bfs(int);
void push(int);
void del();
int a[20][20],q[20],visited[20],f=0,r=0,n;


int main()
{
    int x,i,j;
    printf("enter the no.of vertices:");
    scanf("%d",&n);

printf("enter graph data in matrix form:");
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    for(j=0;j<n;j++)
    {
        visited[j]=0;
    }
printf("enter the starting vertex:");
scanf("%d",&x);
bfs(x);
}
void bfs(int i)
{ int j;
visited[i]=1;
push(i);
printf("\n%d",i);
    while(f!=r)
    {
        i=q[f];

        for(j=0;j<n;j++)
        {
            if(a[i][j]==1 && visited[j]!=1)
            {
                push(j);
                printf("\n%d",j);
                visited[j]=1;
            }

        }
        del();
    }
}
void push(int x)
{
    q[r++]=x;
}
void del()
{
    f++;
}
