//LCS by DP
//backtracking
//O(N^2)
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define LEN 120
int main()
{
    char s1[LEN];
    char s2[LEN];
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int len1=strlen(s1+1);
    int len2=strlen(s2+1);
    int pre[LEN][LEN];
    int dp[LEN][LEN]={0};//初始化為0
    //陣列從1開始可避開dp[i-1][j-1]出現bug
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                pre[i][j]=1;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                pre[i][j]=2;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                pre[i][j]=3;
            }
        }
    }
    printf("LEN = %d\n",dp[len1][len2]);
    //backtracking
    printf("LCS = ");
    int i=len1,j=len2;
    vector<int> ans;
    while(dp[i][j])
    {
        switch(pre[i][j])
        {
            case 1:
                ans.push_back(s1[i]);
                i--;
                j--;
                break;
            case 2:
                i--;
                break;
            case 3:
                j--;
                break;
        }
    }
    for(int k=ans.size()-1;k>=0;k--)
        printf("%c",ans[k]);
    printf("\n");
    return 0;
}
