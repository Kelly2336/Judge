#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int r=1;r<=n;r++)
    {
        int a,f;
        cin>>a>>f;
        for(int i=1;i<=f;i++)
        {
            for(int j=1;j<=a;j++)
            {
                for(int k=1;k<=j;k++)
                {
                    cout<<j;
                }
                cout<<endl;
            }
            for(int j=a-1;j>=1;j--)
            {
                for(int k=1;k<=j;k++)
                {
                    cout<<j;
                }
                cout<<endl;
            }
            if(r!=n||i!=f)cout<<endl;
        }
    }
    return 0;
}
