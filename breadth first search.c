#include <stdio.h>
#include <stdlib.h>
void bfs(int a[10][10],int n,int visited[10],int source)
{
    int queue[10],front=0,rare=-1;
    int i,delnode;
    visited[source]=1;
    queue[++rare]=source;
    while(front<=rare)
    {
        delnode=queue[front++];
        for(i=0;i<n;i++)
        {
            if(a[delnode][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                queue[++rare]=i;
            }
        }
    }
}
int main()
{
    int n,a[10][10],i,j,visited[10],count=0;
    printf("\n read number of nodes ");
    scanf("%d",&n);
    printf("\n read adjectency line");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(a,n,visited,i);
            count++;
        }
    }
    if(count==1)
        printf("\n graph is connected");
    else
        printf("\n graph not connected and has %d components",count);
    return 0;
}
