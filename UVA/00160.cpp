#include<stdio.h>
using namespace std;
int main()
{
    int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int cnt[101][25]={0};
    for(int i=2;i<=100;i++)
    {
        int n=i;
        for(int j=0;j<25&&prime[j]<=i;j++)
        {
            cnt[i][j]+=cnt[i-1][j];
            while(n%prime[j]==0)
            {
                cnt[i][j]++;
                n/=prime[j];
            }
        }
    }
    int N;
    while(1)
    {
        scanf("%d",&N);
        if(!N)break;
        printf("%3d! =",N);
        for(int i=0;prime[i]<=N&&i<15;i++)
        {
            printf("%3d",cnt[N][i]);
        }
        printf("\n");
        if(N>=prime[15])
        {
            printf("      ");
            for(int i=15;i<25&&prime[i]<=N;i++)
            {
                printf("%3d",cnt[N][i]);
            }
            printf("\n");
        }
    }
    return 0;
}
