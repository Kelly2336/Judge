#include<iostream>
using namespace std;
int main()
{
    int s;
    cin>>s;
    for(;s>0;s--)
    {
        int n;
        cin>>n;
        int digit[10]={0};
        for(int i=1;i<=n;i++)
        {
            int h=i;
            while(h>0)
            {
                digit[h%10]++;
                h/=10;
            }
        }
        for(int i=0;i<=8;i++)
        {
            cout<<digit[i]<<" ";
        }
        cout<<digit[9]<<endl;
    }
    return 0;
}
