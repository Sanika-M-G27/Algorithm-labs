#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 256
int Table[SIZE];
void Shifttable(char P[10])
{
    int i,m;
    m=strlen(P);
    for(i=0;i<SIZE;i++)
        Table[i]=m;
    for(i=0;i<=m-2;i++)
        Table[P[i]]=m-1-i;
}
int horspool(char T[50],char P[10])
{
    int i,k,m,n;
    n=strlen(T);
    m=strlen(P);
    Shifttable(P);
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<m && T[i-k]==P[m-1-k])
            k=k+1;
        if(k==m)
            return i-m+1;
        else
            i=i+Table[T[i]];
    }
    return -1;
}
int main()
{
    char T[50],P[10];
    int pos=-1;
    printf("\n Read text \n");
    scanf("%s",&T);
    printf("\n read pattern \n");
    scanf("%s",&P);
    pos=horspool(T,P);
    if(pos==-1)
        printf("\n pattern not found");
    else
        printf("\n pattern found at location %d \n",pos);
    return 0;

}
