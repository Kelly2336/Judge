#include<iostream>
using namespace std;
int main()
{
    long long int dad[100];
    long long int mom[100];
    long long int sum[100];
    dad[0]=1;mom[0]=0;sum[0]=0;
    for(int i=1;i<=80;i++)
    {
        dad[i]=mom[i-1];
        mom[i]=mom[i-1]+dad[i-1];
        sum[i]=dad[i]+mom[i];
    }

    int generation=0;
    while(1)
    {
        cin>>generation;
        if(generation==0)break;
        cout<<sum[generation]<<endl;
    }
    return 0;
}
