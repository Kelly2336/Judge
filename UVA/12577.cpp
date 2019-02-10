#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int cas = 0;
	while(1)
	{
		string s;
		cin >> s;
		if(s == "*")break;
		cout << "Case " << ++cas;
		if(s == "Hajj")cout << ": Hajj-e-Akbar\n";
		else cout << ": Hajj-e-Asghar\n";
	}
	return 0;
}
