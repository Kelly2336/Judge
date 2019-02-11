//union-find
#include <iostream>
#include<string>
#include<map>
using namespace std;
#define maxn 100005
int sz[maxn];
int p[maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		sz[i]=1;
		p[i]=i;
	}
}
void un(int a,int b)
{
	if(sz[a]<sz[b])p[a]=b,sz[b]+=sz[a];
	else p[b]=a,sz[a]+=sz[b];
}
int par(int x)
{
	return p[x]==x ? x : p[x]=par(p[x]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int F;
		cin>>F;
		init();
		map<string,int> m;
		int cnt=1;
		while(F--)
		{
			string a,b;
			cin>>a>>b;
			int ai,bi;
			if(!m[a])ai=m[a]=cnt++;
			else ai=m[a];
			if(!m[b])bi=m[b]=cnt++;
			else bi=m[b];
			if(par(ai)!=par(bi))un(p[ai],p[bi]);
			cout<<sz[p[p[ai]]]<<"\n";
		}
	}
	return 0;
}
