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
    int s=a[left];
    int i=left+1,j=right;
    while(1)
    {
        while(i<=right&&a[i]<s)i++;
        while(j>=0&&a[j]>s)j--;
        if(i<j)swap(a[i],a[j]);
        else break;
    }
    swap(a[left],a[j]);
    quick_sort(a,left,j-1);
    quick_sort(a,j+1,right);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[10000];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
