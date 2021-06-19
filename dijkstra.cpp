#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
const int N = 10;
typedef pair<int,int> pii;
vector<pii> e[N];
int dis[N];
bool vis[N];

void init() {
  e[1].push_back({2, 1});
  e[2].push_back({4, 2});
  e[3].push_back({1, 2});
  e[4].push_back({3, 1});
  e[4].push_back({6, 8});
  e[5].push_back({4, 2});
  e[5].push_back({7, 2});
  e[6].push_back({5, 2});
  e[7].push_back({6, 3});
  e[7].push_back({8, 3});
  e[8].push_back({6, 2});
}

int dijkstra(int s, int h) {
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty()) {
    auto t = q.top(); q.pop();
    int u = t.second, distance = t.first;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto to: e[u]) {
      int v = to.first, w = to.second;
      if (dis[v] > distance + w) {
        dis[v] = distance + w;
        q.push({dis[v], v});
      }
    }
  }
  return dis[h];
}

int main() {
  init();
  cout << dijkstra(1, 8) << '\n';
  return 0;
}
