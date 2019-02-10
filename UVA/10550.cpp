#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n[4];
    while(1)
    {
        int zero=0;
        for(int i=0;i<4;i++)
        {
            cin>>n[i];
            zero+=n[i];
        }
        if(zero==0)break;
        int ans=360*3;
        ans+=((n[0]-n[1])*9+360)%360;
        ans+=((n[2]-n[1])*9+360)%360;
        ans+=((n[2]-n[3])*9+360)%360;
        cout<<ans<<endl;
    }
    return 0;
}
