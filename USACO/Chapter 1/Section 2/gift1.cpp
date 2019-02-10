/*
ID: whitech1
TASK: gift1
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;
int main()
{

    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    int NP;
    scanf("%d",&NP);
    map<string,int> m;
    int money[15];
    memset(money,0,sizeof(money));
    string s[15];
    for(int i=0;i<NP;i++)
    {
        cin>>s[i];
        m[s[i]]=i;
    }
    string give;
    while(cin>>give)
    {
        if(cin.fail())break;
        int sum,p;
        scanf("%d%d",&sum,&p);
        //if(p==0)break;
        if(p)money[m[give]]-=(sum-sum%p);
        for(int i=0;i<p;i++)
        {
            string get;
            cin>>get;
            money[m[get]]+=sum/p;
        }
    }
    for(int i=0;i<NP;i++)
    {
        cout<<s[i];
        printf(" %d",money[i]);
        cout<<endl;
    }
    return 0;
}
