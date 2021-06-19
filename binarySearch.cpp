#include <iostream>
using namespace std;
int find(n, T, x) {
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (T[mid] == x) return mid;
    else if (T[mid] > x) r = mid - 1;
    else l = mid + 1;
  }
  return 0;
}
int main() {
  int n, T[110], x;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> T[i];
  cin >> x;
  int j = find(n, T, x);
  if (j) cout << j;
  else cout << "j=0";
  return 0;
}
