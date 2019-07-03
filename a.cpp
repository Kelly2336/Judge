// 前面讀圖省略
#define maxV 10
#define INF 1e9
int graph[maxV][maxV];

// Init
int dis[maxV];
fill(dis, dis+V, INF);
bool visit[maxV] = {};
dis[s] = 0;    // 起點
