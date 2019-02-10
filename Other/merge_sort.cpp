#include<stdio.h>
using namespace std;
int a[1000005];
int b[1000005];
int n;
void merge_sort(int low,int high)
{
    if(low>=high)return;
    int mid=(low+high)/2;
    merge_sort(low,mid);
    merge_sort(mid+1,high);
    int r1=low,r2=mid+1;
    for(int i=low; i<=high; i++)
    {
        if(r2>high)b[i]=a[r1++];
        else if(r1>mid)b[i]=a[r2++];
        else if(a[r1]<=a[r2])b[i]=a[r1++];
        else b[i]=a[r2++];
    }
    for(int i=low; i<=high; i++)a[i]=b[i];
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        merge_sort(0,n-1);
        for(int i=0; i<n; i++)printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
