//Union-Find tree
#include<stdio.h>
#include<iostream>
using namespace std;
int n=0;
int p[30];
int r[30];
inline int ch(char c)
{
    return c-'A'+1;
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=1;
    }
}
int f(int x)
{
    if(x!=p[x])p[x]=f(p[x]);
    return p[x];
}
void unite(int x,int y)
{
    x=f(x);
    y=f(y);
    if(x!=y)
    {
        n--;
        if(r[x]>r[y])p[y]=x;
        else if(r[x]<r[y])p[x]=y;
        else
        {
            r[x]++;
            p[y]=x;
        }
    }
}
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        char c;
        cin>>c;
        n=ch(c);
        scanf("%c",&c);
        char s[5];
        init();
        while(gets(s))
        {
            if(s[0]=='\0')break;
            unite(ch(s[0]),ch(s[1]));
        }
        printf("%d\n",n);
        if(t)printf("\n");
    }
    return 0;
}
