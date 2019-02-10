/*
ID: whitech1
TASK: dualpal
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=s+1,j=0;j<n;i++)
    {
        int cnt=0;
        for(int b=2;b<=10&&cnt<2;b++)
        {
            vector<int> v;
            int z=i;
            while(z)
            {
                v.push_back(z%b);
                z/=b;
            }
            bool pal=true;
            int len=v.size();
            for(int d=0;d<len/2;d++)
            {
                if(v[d]!=v[len-1-d])
                {
                    pal=false;
                    break;
                }
            }
            if(pal)cnt++;
        }
        if(cnt>=2)
        {
            printf("%d\n",i);
            j++;
        }
    }
    return 0;
}
