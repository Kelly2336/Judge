#include<iostream>
using namespace std;
int f(int i)
{
    if(i<=100)return f(f(i+11));
    else return i-10;
}
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)break;
        cout<<"f91("<<n<<") = "<<f(n)<<endl;
    }
    return 0;
}
