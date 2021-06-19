#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> f(s.size() + 1, vector<int>(t.size() + 1));
  f[0][0] = 0;
  for (int i = 1; i <= s.size(); i++) f[i][0] = i;
  for (int j = 1; j <= t.size(); j++) f[0][j] = j;
  for (int i = 1; i <= s.size(); i++)
    for (int j = 1; j <= t.size(); j++)
      if (s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1];
      else f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]}) + 1;
  cout << f[s.size()][t.size()];
  return 0;
}
