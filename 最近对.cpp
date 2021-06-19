#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<double, double> pdd;

bool cmp_x(const pdd &x, const pdd &y) {
  return x.fi < y.fi;
}

bool cmp_y(const pdd &x, const pdd &y) {
  return x.se < y.se;
}

inline double get_dist(pdd x, pdd y) {
  double dx = x.fi - y.fi;
  double dy = x.se - y.se;
  return sqrt(dx * dx + dy * dy);
}

double EfficientClosePair(vector<pdd> P, vector<pdd> Q, int l, int r) {
  int n = r - l + 1;
  if (n <= 3) {
    double res = 1e18;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        res = min(res, get_dist(P[i], P[j]));
      }
    }
    return res;
  }
  int mid = l + r >> 1;
  vector<pdd> P1, P2, Q1, Q2;
  for (int i = l; i <= mid; i++) P1.push_back(P[i]), Q1.push_back(Q[i]);
  for (int i = mid + 1; i <= r; i++) P2.push_back(P[i]), Q2.push_back(Q[i]);
  double d1 = EfficientClosePair(P1, Q1, l, mid);
  double d2 = EfficientClosePair(P2, Q2, mid+1, r);
  double d = min(d1, d2);
  double m = P[mid].fi;
  vector<pdd> S;
  for (pdd i: Q)
    if (fabs(i.se - m) < d) S.push_back(i);
  double dminsq = d * d;
  int num = S.size();
  for (int i = 0; i <= num - 2; i++) {
    int k = i + 1;
    while (k <= num - 1 && (S[k].se - S[i].se) * (S[k].se - S[i].se) < dminsq) {
      dminsq = min(dminsq, (S[k].fi - S[i].fi) * (S[k].fi - S[i].fi) + (S[k].se - S[i].se) * (S[k].se - S[i].se));
      k = k + 1;
    }
  }
  return sqrt(dminsq);
}

int main() {
  int n;
  cin >> n;
  vector<pdd> P, Q;
  for (int i = 1; i <= n; i++) {
    double x, y;
    cin >> x >> y;
    pdd point = {x, y};
    P.push_back(point);
    Q.push_back(point);
  }
  sort(P.begin(), P.end(), cmp_x);
  sort(Q.begin(), Q.end(), cmp_y);
  cout << EfficientClosePair(P, Q, 0, n - 1) << '\n';
  return 0;
}
