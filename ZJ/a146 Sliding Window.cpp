//Sliding Window
//max
//單調隊列
#include<stdio.h>
#include<queue>
using namespace std;
#define maxn 1000010
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[maxn];
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    deque<int> dq;
    while(!dq.empty()) dq.pop_back();
    for(int i=0; i<k && i<n; i++)
    {
        while( !dq.empty() && dq.back()<a[i] ) dq.pop_back();
        dq.push_back(a[i]);
    }
    printf("%d",dq.front());
    for(int i=k; i<n; i++)
    {
        if( a[i-k]==dq.front() ) dq.pop_front();  //delete expired
        while( !dq.empty() && dq.back()<a[i] ) dq.pop_back();
        dq.push_back(a[i]);
        printf(" %d",dq.front());
    }
    return 0;
}
