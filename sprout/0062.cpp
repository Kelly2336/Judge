//數獨
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
int a[10][10];
int visit_i[10][10];
int visit_j[10][10];
int visit_sq[4][4][10];

vector<int>qi;
vector<int>qj;

bool success;
int sz;

void solve(int i)
{
    if(success)return;
    if(i==sz)
    {
        for(int ii=0;ii<9;ii++)
        {
            for(int jj=0;jj<9;jj++)
            {
                printf("%d",a[ii][jj]);
            }
        }
        printf("\n");
        success=true;
        return;
    }
    int x=qi[i];
    int y=qj[i];
    for(int h=1;h<=9 && !success;h++)
    {
        if(!visit_i[x][h] && !visit_j[y][h] && !visit_sq[x/3][y/3][h])
        {
            visit_i[x][h]++;
            visit_j[y][h]++;
            visit_sq[x/3][y/3][h]++;
            a[x][y]=h;
            solve(i+1);
            visit_i[x][h]--;
            visit_j[y][h]--;
            visit_sq[x/3][y/3][h]--;
        }
    }
}

int main()
{
    while(1)
    {
        char s[100];
        scanf(" %s",s);
        if(s[0]=='e')break;
        int si=0;
        memset(a,0,sizeof(a));
        memset(visit_i,0,sizeof(visit_i));
        memset(visit_j,0,sizeof(visit_j));
        memset(visit_sq,0,sizeof(visit_sq));
        qi.clear();
        qj.clear();
        bool possible=true;
        for(int i=0; i<9 && possible; i++)
        {
            for(int j=0; j<9; j++)
            {
                char x=s[si];
                si++;
                if(x!='.')
                {
                    int r=x-'0';
                    a[i][j]=r;
                    visit_i[i][r]++;
                    visit_j[j][r]++;
                    visit_sq[i/3][j/3][r]++;
                    if(visit_i[i][r]!=1||visit_j[j][r]!=1||visit_sq[i/3][j/3][r]!=1)
                    {
                        possible=false;
                        break;
                    }
                }
                else
                {
                    qi.push_back(i);
                    qj.push_back(j);
                }
            }
        }
        if(!possible)
        {
            printf("No solution.\n");
            continue;
        }
        sz=qi.size();
        success=false;
        solve(0);
        if(!success)printf("No solution.\n");
    }
    return 0;
}
