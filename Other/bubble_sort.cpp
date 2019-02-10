#include<stdio.h>
using namespace std;
void swap(int& a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void bubble_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        bool sorted=true;
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                sorted=false;
            }
        }
        if(sorted)return;
    }
}
int main()
{
    int a[100000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    bubble_sort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
