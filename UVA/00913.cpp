#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        long long int n;
        cin>>n;
        if(cin.fail())break;
        n=(1+n)*(1+n)/4;
        n=(n*2-1)*3-6;
        cout<<n<<endl;
    }
    return 0;
}
