#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define maxm 2005
#define maxn 50005
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int p[maxm];
int rnk[maxm];
void init(int m)
{
	for(int i=0;i<=m;i++)
	{
		p[i] = i;
		rnk[i] = 1;
	}
}
int par(int x)
{
	if(p[x]==x)return x;
	else return p[x] = par(p[x]);
}
void uni(int a,int b)
{
	if(rnk[a]<rnk[b])
		p[a] = b;
	else if(rnk[a]>rnk[b])
		p[b] = a;
	else
	{
		p[a] = b;
		rnk[b]++;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	ios::sync_with_stdio(false);
	while(T--)
	{
		int m,n;
		cin >> m >> n;
		map<string,int> mp;
		int cnt = 0;
		iii e[maxn];
		for(int i=0;i<n;i++)
		{
			string a,b;
			int c;
			cin >> a >> b >> c;
			if(!mp[a]) mp[a] = ++cnt;
			if(!mp[b]) mp[b] = ++cnt;
			e[i] = iii(c,ii(mp[a],mp[b]));
		}
		sort(e,e+n);
		int sum = 0;
		init(m);
		for(int i=1,ei=0;i<m;i++)
		{
			while(ei<n)
			{
				int a = e[ei].second.first;
				int b = e[ei].second.second;
				int c = e[ei].first;
				ei++;
				if(par(a)!=par(b))
				{
					sum += c;
					uni(p[a],p[b]);
					break;
				}
			}
		}
		cout << sum << "\n";
		if(T)cout << "\n";
	}
	return 0;
}
