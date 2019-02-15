#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<double,double> Point;
#define x first
#define y second
#define maxn 10005
#define INF 10005
#define exp 1e-5
Point p[maxn],t[maxn];
bool cmpy(Point a,Point b){return a.y<b.y;}
inline double dist(Point a,Point b)
{
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
double DC(int L,int R)
{
	if(L>=R)return INF;
	int M = (L+R)>>1;
	double ans = min(DC(L,M),DC(M+1,R));
	int cnt = 0;
	for(int i=M;i>=L;i--)
	{
		if(p[M].x-p[i].x<ans)
			t[cnt++] = p[i];
	}
	for(int i=M+1;i<=R;i++)
	{
		if(p[i].x-p[M].x<ans)
			t[cnt++] = p[i];
	}
	sort(t,t+cnt,cmpy);
	for(int i=0;i<cnt;i++)
	{
		for(int j=1;j<=3&&i+j<cnt;j++)
		{
			ans = min(ans,dist(t[i],t[i+j]));
		}
	}
	return ans;
}
double ClosestPairDist(int n)
{
	sort(p,p+n);
	for(int i=1;i<n;i++)//重點
		if(dist(p[i],p[i-1])<exp)
			return 0;
	return DC(0,n-1);
}
int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		double ans = ClosestPairDist(n);
		if(ans>=10000)printf("INFINITY\n");
		else printf("%.4f\n",ans);
	}
	return 0;
}
