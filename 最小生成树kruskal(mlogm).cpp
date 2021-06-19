const int N = 55, M = N * N / 2, inf = 0x3f3f3f3f;

struct E {
  int u, v, w;
  E(){}
  E(int _u, int _v, int _w) {
    u = _u, v = _v, w = _w;
  }
  bool operator < (const E &x) const {
    return w < x.w;
  }
}e[M];

int n, m, fa[N];

int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}

int kruskal() {
  sort(e + 1, e + m + 1);
  for (int i = 0; i <= n; i++) fa[i] = i;
  int res = 0, cnt = 0;
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v;
    u = find(u), v = find(v);
    if (u != v) {
      res += e[i].w;
      fa[u] = v;
      ++cnt;
    }
    if (cnt == n - 1) break;
  }
  if (cnt < n - 1) return inf;
  return res;
}
