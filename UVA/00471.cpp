#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pLL;
LL n;
int visit[10];
vector<pLL> ans;
int cnt;
bool check(LL x)
{
	if(!x)return false;
	bool used[10]={0};
	while(x)
	{
		int r=x%10;
		if(used[r])return false;
		used[r]=true;
		x/=10;
	}
	return true;
}
void per(LL sum,int i,int len)
{
	LL p = 1;
	for(int j=0;j<i;j++)
		p *= 10;
	for(int j=0;j<10;j++)
	{
		if(visit[j])continue;
		visit[j]=true;
		LL sum2 = j*p + sum;
		LL pro = sum2*n;
		if(j && check(pro))
		{
			ans.push_back(pLL(sum2,pro));
			cnt ++;
		}
		if(i<len)per(sum2,i+1,len);
		visit[j]=false;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		n = 0;
		char s[20];
		scanf(" %s",s);
		ans.clear();
		cnt = 0;
		int len = strlen(s);
		for(int i=0;i<len;i++)
			n = n*10 + s[i]-'0';
		memset(visit,0,sizeof(visit));
		per(0,0,10-len);
		sort(ans.begin(),ans.end());
		for(int i=0;i<cnt;i++)
			printf("%lld / %lld = %s\n",ans[i].second,ans[i].first,s);
		if(T)printf("\n");
	}
	return 0;
}
