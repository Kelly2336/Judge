#include<bits/stdc++.h>
using namespace std;
//int mod[4]={10,100,1000,10000};
/*vector<int> v[4];
void f(int i)
{
    for(int j=0;j<mod[i];j++)
        for(int k=0;k<mod[i];k++)
            if( (j+k)*(j+k) == j*mod[i]+k )
                v[i].push_back(j*mod[i]+k);
    sz[i]=v[i].size();
}*/
int sz[4]={3,5,5,9};
int v[4][10]={{0,1,81},{0,1,2025,3025,9801},{0,1,88209,494209,998001},{0,1,4941729,7441984,24502500,25502500,52881984,60481729,99980001}};
int main()
{
    //for(int i=0;i<4;i++)f(i);
    int n;
    while(scanf("%d",&n)==1)
    {
        int x=n/2-1;
        for(int i=0;i<sz[x];i++)
        {
            if(n==2)printf("%02d\n",v[x][i]);
            else if(n==4)printf("%04d\n",v[x][i]);
            else if(n==6)printf("%06d\n",v[x][i]);
            else if(n==8)printf("%08d\n",v[x][i]);
        }
    }
    return 0;
}
/*
2
00
01
81
4
0000
0001
2025
3025
9801
6
000000
000001
088209
494209
998001
8
00000000
00000001
04941729
07441984
24502500
25502500
52881984
60481729
99980001
*/
