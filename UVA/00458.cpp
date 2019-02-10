#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char n[100];
	while(1)
	{
		cin.getline(n,100);
		if(cin.fail())break;
		int len=strlen(n);
		for(int i=0;i<len;i++)
		{
			n[i]=n[i]-7;
			cout<<n[i];
		}
		cout<<endl;
	}
	return 0;
}
