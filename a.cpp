    for(int uu=0; uu<V; uu++)
    {
        if( graph[u][uu]!=INF ) //和u相鄰?
        {
            if( dis[uu] > dis[u]+graph[u][uu] )
                dis[uu] = dis[u]+graph[u][uu] ;
        }
    }
}
