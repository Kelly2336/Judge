#include<stdio.h>
using namespace std;
void swap(int& a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void insertion_sort(int a[],int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]<a[j])swap(a[i],a[j]);
            else break;
        }
    }
}
int main()
{
    int a[100000];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    insertion_sort(a,n);
    for(int i=0; i<n; i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}

