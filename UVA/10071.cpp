#include<iostream>
using namespace std;
int main()
{
    int v,t;
    while(1)
    {
        cin>>v>>t;
        if(cin.fail())break;
        cout<<2*v*t<<endl;
    }
    return 0;
}
