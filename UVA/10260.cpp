#include<iostream>
using namespace std;

int main()
{
	char a[7][10]={
		"AEIOUHWY",
		"BFPV",
		"CGJKQSXZ",
		"DT",
		"L",
		"MN",
		"R"
	};
	int t[26]={0};
	for(int i=0;i<7;i++)
	{
		for(int j=0;a[i][j];j++)
		{
			t[a[i][j]-'A']=i;
		}
	}
	ios_base::sync_with_stdio(false);
	char s[25];
	while(cin>>s)
	{
		int r=0;
		for(int i=0;s[i];i++)
		{
			int rr=t[s[i]-'A'];
			if(rr&&r!=rr)cout<<rr;
			r=rr;
		}
		cout<<"\n";
	}
	return 0;
}
