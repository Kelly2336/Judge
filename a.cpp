void Union(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    if( rnk[px]>rnk[py] ) par[py] = px;  
    else if( rnk[px]<rnk[py] ) par[px] = py;
    else par[px] = py, rnk[py]++;
}
