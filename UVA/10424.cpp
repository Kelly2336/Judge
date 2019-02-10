#include<bits/stdc++.h>
using namespace std;
int f(char a[],int len)
{
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(isupper(a[i]))ans+=a[i]-'A'+1;
        else if(islower(a[i]))ans+=a[i]-'a'+1;
    }
    return ans;
}
int digit(int n)
{
    if(n<10)return n;
    int nn=0;
    while(n)
    {
        nn+=n%10;
        n/=10;
    }
    return digit(nn);
}
int main()
{
    char a[100],b[100];
    while(1)
    {
        cin.getline(a,100);
        if(cin.fail())break;
        cin.getline(b,100);
        int A=digit(f(a,strlen(a)));
        int B=digit(f(b,strlen(b)));
        if(A>B){int t=A;A=B;B=t;}
        printf("%.2lf %%\n",A*100.0/B);
    }
    return 0;
}
