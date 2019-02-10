#include<iostream>
using namespace std;
int main()
{
    int n;
    int r=0;
    while(1)
    {
        cin>>n;
        if(n==0)break;
        r++;
        int a[50];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int ave=sum/n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>ave)sum+=a[i]-ave;
        }
        cout<<"Set #"<<r<<endl;
        cout<<"The minimum number of moves is "<<sum<<"."<<endl;
    }
    return 0;
}
