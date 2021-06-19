#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int,int> > tr(n * 2, {0, 0});
  vector<int> val(n * 2);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    q.push({x, i});
    val[i] = x;
  }
  int cnt = n;
  while (q.size() > 1) {
    auto x = q.top();
    q.pop();
    auto y = q.top();
    q.pop();
    int new_node = ++cnt;
    int new_val = x.first + y.first;
    tr[new_node].first = x.second;
    tr[new_node].second = y.second;
    q.push({new_val, new_node});
    val[new_node] = new_val;
  }
  int rt = cnt;
  // bfs 
  queue<int> Q;
  Q.push(rt);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    printf("node[%d].val : %d left child : %d right child : %d\n", u,val[u],tr[u].first,tr[u].second);
    if (tr[u].first) Q.push(tr[u].first);
    if (tr[u].second) Q.push(tr[u].second);
  }
  return 0;
} 
