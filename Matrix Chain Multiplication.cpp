#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 0; i < n + 1; i++) {
    cin >> p[i];
  }
  constexpr int inf = 1e9;
  vector<vector<int> > dp(n + 1, vector<int>(n + 1, inf));
  for (int i = 0; i < n + 1; i++) {
    dp[i][i] = 0;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      printf("dp[%d][%d] = %d ",i,j,dp[i][j]);
    }
    puts("");
  }
  cout << dp[1][n] << '\n';
  return 0;
}
