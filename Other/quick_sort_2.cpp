#include<stdio.h>
using namespace std;
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void quick_sort(int a[],int left,int right)
{
    if(left>=right)return;
    int i=left;
    int s=a[right];
    for(int j=left;j<right;j++)
    {
        if(a[j]<s)swap(a[i++],a[j]);
    }
    swap(a[i],a[right]);
    quick_sort(a,left,i-1);
    quick_sort(a,i+1,right);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[100000];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
