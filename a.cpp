int par[maxn];
int rnk[maxn];
int init(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = i;
        rnk[i] = 1;
    }
}
