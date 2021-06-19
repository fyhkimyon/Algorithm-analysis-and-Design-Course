#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r) {
  int i = l, j = mid + 1;
  vector<int> v;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) v.push_back(a[i++]);
    else v.push_back(a[j++]);
  }
  while (i <= mid) v.push_back(a[i++]);
  while (j <= r) v.push_back(a[j++]);
  int idx = l;
  for (int val: v) a[idx++] = val;
}

void merge_sort(vector<int> &a, int l, int r) {
  if (l >= r) return;
  int mid = l + r >> 1;
  merge_sort(a, l, mid);
  merge_sort(a, mid+1, r);
  merge(a, l, mid, r);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  merge_sort(a, 1, n);
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
  return 0;
}
