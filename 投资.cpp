#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > profit(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      cin >> profit[i][j];
    }
  }
  vector<vector<int> > f(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int a=-1,b=-1,c=-1,d=-1;
      for (int k = 0; k <= j; k++) {
        if (f[i-1][j-k] + profit[i][k] > f[i][j]) {
          f[i][j] = f[i-1][j-k] + profit[i][k];
          a = i-1,b=j-k,c=i,d=j;
        }
      }
      if (a != -1) printf("f[%d][%d] -> f[%d][%d]\n",a,b,c,d);
    }
  }
  cout << f[n][m] << '\n';
  return 0;
} 
/*
4 5
0 11 12 13 14 15
0 0 5 10 15 20
0 2 10 30 32 40
0 20 21 22 23 24
*/
