//图不联通返回inf 

const int N = 510, inf = 0x3f3f3f3f;
int n;
int e[N][N];
int dis[N];
bool st[N];
 
int prim() {
  memset(dis,0x3f,sizeof dis);
  memset(st, false, sizeof st);
  int res = 0;
  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t == -1 || dis[t] > dis[j]))
        t = j;
    if (i && dis[t] == inf) return inf;
    if (i) res += dis[t];
    st[t] = true;
    for (int j = 1; j <= n; j++) dis[j] = min(dis[j], e[t][j]);
  }
  return res;
}
