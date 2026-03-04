#include <stdio.h>
#include <stdlib.h>
int count;
void merge(int a[10],int l,int m,int r)
{

    int i,j,k ,B[10];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=r)
    {
        count++;
        if(a[i]<a[j])
            B[k++]=a[i++];
        else
            B[k++]=a[j++];
    }
    while(i<=m)
        B[k++]=a[i++];
    while(j<=r)
        B[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=B[i];
}
void mergesort(int a[10],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int i,l,a[10],n;
    printf("\n enter an array size:");
    scanf("%d",&n);
    printf("\n read the array elements are\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\n sorted elements are:");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n total number of comparison :%d",count);
    return 0;
}
