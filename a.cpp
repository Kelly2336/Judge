// 找x屬於哪一個集合
// 順便把x直接接到集合代表的下面
// 複雜度是樹的高度，所以邊做邊把樹壓平
int Find(int x)
{
    if( x != par[x] ) par[x] = Find(par[x]);
    return par[x];
}
