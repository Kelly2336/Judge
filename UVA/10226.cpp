//實測 不只有英文字母
#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<map>
#include<string>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    getchar();
    while(n--)
    {
        string s;
        map<string,int> m;
        map<string,int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter=m.begin())m.erase(iter);
        int cnt=0;
        while(1)
        {
            getline(cin,s);
            if(cin.fail()||s.compare("")==0)break;
            m[s]++;
            cnt++;
        }
        for(iter=m.begin();iter!=m.end();iter++)
        {
            cout << iter->first;
            printf(" %.4lf\n",iter->second*100.0/cnt);
        }
        if(n)puts("");
    }
    return 0;
}
