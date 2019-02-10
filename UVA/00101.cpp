#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=30;
int n;
vector<int> pile[maxn];

void find_block(int a,int& p,int& h)
{
    for(p=0; p<n; p++)
    {
        for(h=0; h<pile[p].size(); h++)
        {
            //printf("%d %d %d\n",p,h,pile[p][h]);
            if(pile[p][h]==a)return;
        }
    }
}
void clear_above(int p,int h)
{
    for(int i=h+1; i<pile[p].size(); i++)
    {
        int t=pile[p][i];
        pile[t].push_back(t);
    }
    pile[p].resize(h+1);
}
void pile_onto(int p,int h,int p2)
{
    for(int i=h; i<pile[p].size(); i++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}
void print()
{
    for(int i=0; i<n; i++)
    {
        printf("%d:",i);
        for(int j=0; j<pile[i].size(); j++)
        {
            printf(" %d",pile[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a,b;
    while(cin>>n)
    {
        string s1,s2;
        for(int i=0; i<n; i++)
        {
            pile[i].clear();
            pile[i].push_back(i);
        }
        while(cin>>s1)
        {
            if(s1=="quit")break;
            cin>>a>>s2>>b;
            int pa=0,pb=0,ha=0,hb=0;
            find_block(a,pa,ha);
            find_block(b,pb,hb);
            //printf("%d %d %d %d %d %d\n",a,pa,ha,b,pb,hb);
            if(pa==pb)continue;
            if(s2=="onto")clear_above(pb,hb);
            if(s1=="move")clear_above(pa,ha);
            pile_onto(pa,ha,pb);
        }
        print();
    }
    return 0;
}
