#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    map<string,int> m;
    while(n--)
    {
        string s;
        cin>>s;
        m[s]++;
        getline(cin,s);
    }
    map<string,int>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++)
    {
        cout<<iter->first;
        printf(" %d\n",iter->second);
    }
    return 0;
}
