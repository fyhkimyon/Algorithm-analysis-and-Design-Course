#include <iostream>
using namespace std;
int find(n, T, x) {
  for (int i = 1; i <= n; i++)
    if (T[i] == x) return i;
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
