#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t[205];
    for(int i=0;i<=200;i++)t[i]=i*i*i;
    for(int a=6;a<=200;a++)
    {
        double r=t[a]/3.0;
        for(int b=2;t[b]<=r;b++)
        {
            //t[b]+t[c]<=t[a]*2/3
            double k=r*2-t[b];
            for(int c=b;t[c]<=k;c++)
            {
                int ddd=t[a]-t[b]-t[c];
                int d=lower_bound(t+1,t+200,ddd)-t;
                if(d<c)break;
                if(t[d]==ddd)printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
            }
        }
    }
    return 0;
}
