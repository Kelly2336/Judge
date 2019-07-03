for(int i=0; i<V-1; i++) // V-1次就夠了
{
    // 找離起點最近且還沒被用過的點
    int u , min_dis = INF;
    for(int j=0; j<=V; j++)
    {
        if( !visit[j] && dis[j]<min_dis )
            u = j, min_dis = dis[j];
    }
    visit[u] = true;
