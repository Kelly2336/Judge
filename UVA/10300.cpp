#include<iostream>
using namespace std;
int main()
{
    int n,f;
    cin>>n;
    for(int r=0;r<n;r++)
    {
        long long int sum=0;
        long long int a[3];
        cin>>f;
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[j];
            }
            sum+=a[0]*a[2];
        }
        cout<<sum<<endl;
    }
    return 0;
}
