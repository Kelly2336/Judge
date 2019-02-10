#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int c;
    cin>>c;
    for(int v=0;v<c;v++)
    {
        int n;
        int a[1000];
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        double ave=sum*1.0/n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>ave)sum++;
        }
        printf("%.3f%%\n",sum*100.0/n);
    }
    return 0;
}
