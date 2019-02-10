#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string a,b;
	while(1)
	{
		getline(cin,a);
		if(cin.fail())break;
		getline(cin,b);
		int cnt_a[26]={0};
		int cnt_b[26]={0};
		for(int i=0;a[i];i++)
			cnt_a[a[i]-'a']++;
		for(int i=0;b[i];i++)
			cnt_b[b[i]-'a']++;
		for(int i=0;i<26;i++)
		{
			int cnt = min(cnt_a[i],cnt_b[i]);
			while(cnt--)putchar(i+'a');
		}
		putchar('\n');
	}
	return 0;
}
