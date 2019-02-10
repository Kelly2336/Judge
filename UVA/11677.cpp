#include<iostream>
using namespace std;
int main()
{
    int h1,m1,h2,m2;
    while(1)
    {
        cin>>h1>>m1>>h2>>m2;
        if((h1||m1||h2||m2)==0)break;
        m1=h1*60+m1;
        m2=h2*60+m2;
        cout<<(m2-m1+24*60)%(24*60)<<endl;
    }
    return 0;
}
