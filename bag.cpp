#include <bits/stdc++.h>

using namespace std; 

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int ans = 0;
  sort(w.begin(), w.end());
  for (int i = 0; i < n && c >= w[i]; i++) {
    c -= w[i];
    ++ans;
  }
  cout << ans << '\n';
  return 0;
} 
