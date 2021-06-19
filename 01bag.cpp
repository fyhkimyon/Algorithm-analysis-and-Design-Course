#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1), w(n + 1), dp(m + 1, 0);
  for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= v[i]; j--) {
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[m];
  return 0;
}
