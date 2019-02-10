//union-find tree
#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int p[maxn];
int high[maxn];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        p[i]=i;
        high[i]=1;
    }
}
int fp(int x)//finf parent
{
    if(p[x]!=x)p[x]=fp(p[x]);
    return p[x];
}
void connect(int a,int b)
{
    if(high[a]>high[b])p[b]=a;
    else if(high[a]<high[b])p[a]=b;
    else
    {
        p[a]=b;
        high[b]++;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d ",&n);
        init(n);
        int yes=0,no=0;
        while(1)
        {
            string s;
            getline(cin,s);
            if(cin.fail()||s=="")break;
            char q;
            int a,b;
            stringstream ss;
            ss.clear();
            ss.str(s);
            ss>>q;
            ss>>a>>b;
            if(q=='q')
            {
                if(fp(a)==fp(b))yes++;
                else no++;
            }
            else
            {
                connect(fp(a),fp(b));
            }
        }
        printf("%d,%d\n",yes,no);
        if(t)printf("\n");
    }
    return 0;
}
