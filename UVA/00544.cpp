//³Ìµu¸ô®| ³Ì¤j²~ÀV
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<set>
#define INT 20000000
using namespace std;
int main()
{
    int n,r;
    int cas=0;
    while(scanf("%d%d",&n,&r)==2&&n&&r)
    {
        cas++;
        map<string,int> m;
        set<string> s;
        s.clear();
        int graph[210][210];
        memset(graph,0,sizeof(graph));
        int ni=0;
        for(int i=0;i<r;i++)
        {
            string n1,n2;
            int d;
            cin>>n1>>n2>>d;
            if(s.count(n1)==0)
            {
                m[n1]=ni;ni++;
                s.insert(n1);
            }
            if(s.count(n2)==0)
            {
                m[n2]=ni;ni++;
                s.insert(n2);
            }
            graph[m[n1]][m[n2]]=d;
            graph[m[n2]][m[n1]]=d;
        }
        string ss,ee;
        cin>>ss>>ee;
        int st=m[ss];
        int en=m[ee];
        int w[210];
        memset(w,-1,sizeof(w));
        int vis[210];
        memset(vis,0,sizeof(vis));
        w[st]=INT;
        for(int i=0;i<n;i++)
        {
            int mi=-1;
            int Max=0;
            for(int j=0;j<n;j++)
            {
                if(!vis[j]&&w[j]>Max)
                {
                    Max=w[j];
                    mi=j;
                }
            }
            if(mi==-1)break;
            vis[mi]=1;
            for(int j=0;j<n;j++)
            {
                if(graph[j][mi]&&!vis[j])
                {
                    w[j]=max(min(w[mi],graph[j][mi]),w[j]);
                }
            }
        }
        printf("Scenario #%d\n",cas);
        printf("%d tons\n\n",w[en]);
    }
    return 0;
}
