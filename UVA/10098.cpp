#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<set>
#include<string>
using namespace std;
char a[15];
int ans[15];
int visit[15];
set<string> ss;
void solve(int cur,int len)
{
    if(cur==len)
    {
        string s="";
        for(int i=0; i<len; i++)
        {
            s=s+a[ans[i]];
        }
        if(ss.count(s)==0)
        {
            cout<<s<<endl;
            ss.insert(s);
        }
        return;
    }
    for(int i=0; i<len; i++)
    {
        if(!visit[i])
        {
            visit[i]=1;
            ans[cur]=i;
            solve(cur+1,len);
            visit[i]=0;
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int t=1; t<=n; t++)
        {
            scanf("%s",a);
            int len=strlen(a);
            sort(a,a+len);
            memset(visit,0,sizeof(visit));
            ss.clear();
            solve(0,len);
            printf("\n");
        }
    }
    return 0;
}
