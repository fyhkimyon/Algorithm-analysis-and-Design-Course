#include <bits/stdc++.h>

using namespace std;

int get_mid(vector<int> v, int len) {
  int b = (len + 4) / 5;
  vector<vector<int> > vec(b, vector<int>());
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    vec[cnt].push_back(v[i]);
    if ((i + 1) % 5 == 0) ++cnt;
  }
  for (int i = 0; i < b; i++) 
    sort(vec[i].begin(), vec[i].end());
  vector<int> nxt;
  for (int i = 0; i < b; i++) {
    int L = vec[i].size();
    int m = L >> 1;
    nxt.push_back(vec[i][m]);
  }
  int nxtlen = nxt.size();
  if (nxtlen == 1)
    return nxt.back();
  else
    return get_mid(nxt, nxtlen);
}

int get_k(vector<int> v, int l, int r, int k) {
  int x = get_mid(v, r - l + 1);
  vector<int> a, b, c;
  int cnt = 0;
  for (int i = l; i <= r; i++)
    if (v[i] < x) a.push_back(v[i]);
    else {
      if (v[i] == x) ++cnt;
      b.push_back(v[i]);
      if (v[i] > x) c.push_back(v[i]);
    }
  int alen = a.size(), blen = b.size();
  if (!alen) {
    if (cnt >= k) return x;
    else {
      int clen = c.size();
      return get_k(c, 0, clen -  1, k - cnt);
    }
  }
  if (alen + 1 == k) return x;
  else if (alen >= k) return get_k(a, 0, alen - 1, k);
  else return get_k(b, 0, blen - 1, k - alen);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int k;
  cin >> k;
  cout << get_k(v, 0, n - 1, k) << '\n';
  return 0;
}
