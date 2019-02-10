#include<iostream>
using namespace std;
int main()
{
    long long int sum[100000];
    sum[0]=0;
    for(int i=1;i<100000;i++)
    {
        sum[i]=sum[i-1]+i*i;
    }
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<sum[n]<<endl;
    }
    return 0;
}
