#include<iostream>
using namespace std;
int main()
{
    long long int a[51];
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=50;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        cout<<a[n]<<endl;
    }
    return 0;
}
