#include<stdio.h>
using namespace std;
void swap(int& a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void selection_sort(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        int mi=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mi])mi=j;
        }
        swap(a[i],a[mi]);
    }
}
int main()
{
    int a[100000];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    selection_sort(a,n);
    for(int i=0; i<n; i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
