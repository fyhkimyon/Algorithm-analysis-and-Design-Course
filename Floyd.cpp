#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
int dis[N][N];
const int n = 4;

void init() {
  memset(dis,0x3f,sizeof dis);
  for(int i = 1; i <= n; i++) dis[i][i] = 0;
  dis[1][2] = 2;
  dis[1][3] = 6;
  dis[1][4] = 4;
  dis[2][3] = 3;
  dis[3][1] = 7;
  dis[3][4] = 1;
  dis[4][1] = 5;
  dis[4][3] = 12;
}

void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

int main() {
  init();
  floyd();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << dis[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
