//MST
//Kruskal
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double x[100];
double y[100];
int p[100];
int h[100];
struct Edge
{
    int a,b;
    double w;
}E[5000];
bool operator<(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}
void init()
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        h[i]=1;
    }
}
int Find(int x)
{
    if(p[x]!=x)p[x]=Find(p[x]);
    return p[x];
}
void unite(int x,int y)
{
    if(h[x]>h[y])p[y]=x;
    else if(h[x]<h[y])p[x]=y;
    else
    {
        h[x]++;
        p[y]=x;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ei=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            for(int j=0;j<i;j++)
            {
                E[ei].a=i;
                E[ei].b=j;
                E[ei].w=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
                ei++;
            }
        }
        init();
        sort(E,E+ei);
        double sum=0;
        ei=0;
        for(int r=1;r<n;r++)
        {
            while(Find(E[ei].a)==Find(E[ei].b))ei++;
            sum+=E[ei].w;
            unite(p[E[ei].a],p[E[ei].b]);
            ei++;
        }
        printf("%.2lf\n",sum);
        if(t)printf("\n");
    }
    return 0;
}
