#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int t=0;t<n;t++)
    {
        int e,f,c;
        cin>>e>>f>>c;
        e+=f;
        int sum=0;
        while(e>=c)
        {
            sum+=e/c;
            e=e/c+e%c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
