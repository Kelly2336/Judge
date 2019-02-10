#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int u=0;
    while(1)
    {
        char s[1001];
        cin.getline(s,1001);
        if(cin.fail())break;
        if(u!=0)cout<<endl;
        u++;
        int len=strlen(s);
        int a[256]={0};
        memset(a,0,sizeof(a));
        for(int i=0;i<len;i++)
        {
            a[s[i]-'\0']+=1;
        }
        int min_=1100;
        while(min_!=1000)
        {
            min_=1000;
            int m=0;
            for(int i=255;i>=0;i--)
            {
                if(min_>a[i]&&a[i]!=0)
                {
                    min_=a[i];
                    m=i;
                }
            }
            if(min_<1000)cout<<m<<" "<<a[m]<<endl;
            a[m]=0;
        }
    }
    return 0;
}
