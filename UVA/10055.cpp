#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    while(1)
    {
        long long int a,b;
        cin>>a>>b;
        if(cin.fail())break;
        cout<<abs(a-b)<<endl;
    }
    return 0;
}
