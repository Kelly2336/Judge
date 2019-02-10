#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
struct elephant
{
    int w;
    int s;
    int id;
}e[1005];
int cmp(const void*p,const void*q)
{
    return ((elephant*)p)->w-((elephant*)q)->w;
}
int main()
{
    int n=1;
    while(scanf("%d%d",&e[n].w,&e[n].s)==2)
    {
        e[n].id=n;
        n++;
    }
    n--;
    qsort(e+1,n,sizeof(elephant),cmp);
    int len[1005];
    int pre[1005];
    fill(len,len+n+1,1);
    memset(pre,-1,n+1);
    int max_len=1;
    int last=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(e[j].s>e[i].s&&len[j]+1>len[i])
            {
                len[i]=len[j]+1;
                pre[i]=j;
            }
        }
        if(len[i]>max_len)
        {
            max_len=len[i];
            last=i;
        }
    }
    printf("%d\n",max_len);
    stack<int> st;
    while(!st.empty())st.pop();
    while(last!=-1)
    {
        st.push(e[last].id);
        last=pre[last];
    }
    while(!st.empty())
    {
        printf("%d\n",st.top());
        st.pop();
    }
    return 0;
}
