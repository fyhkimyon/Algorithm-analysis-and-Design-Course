#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, e, m;
  cin >> n >> e >> m;
  vector<vector<int>> g(n, vector<int>());
  vector<int> col(n, 0);
  function<void(int,int)> add = [&](int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  };
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    add(u, v);
  }
  vector<vector<int>> ans;
  function<void(int,int)> dfs = [&](int u, int cnt) {
    if (cnt == n) {
      vector<int> v;
      for (int i = 0; i < n; i++) {
        v.push_back(col[i]);
      }
      ans.push_back(v);
      return;
    }
    for (int v: g[u]) {
      if (col[v]) continue;
      for (int c = 1; c <= m; c++) {
        bool ok = true;
        for (int to: g[v]) {
          if (col[to] == c) {
            ok = false;
            break;
          }
        }
        if (ok) {
          col[v] = c;
          dfs(v, cnt + 1);
          col[v] = 0;
        }
      }
    }
  };
  for (int i = 1; i <= m; i++) {
    col[0] = i;
    dfs(0, 1);
  }
  for (auto vec: ans) {
    for (int c: vec) cout << c << ' ';
    cout << '\n';
  }
  return 0;
}
