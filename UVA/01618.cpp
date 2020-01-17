#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> a) {
  int n = a.size();
  vector<vector<int>> mx(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    mx[i][i] = a[i];
    for (int j = i + 1; j < n; j++) {
      mx[i][j] = max(mx[i][j-1], a[j]);
    }
  }

  vector<set<int>> s(n);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      s[i].insert(a[j]);

  for (int p = 0; p < n - 3; p++) {
    for (int r = p + 2; r < n - 1; r++) {
      int nq = mx[p+1][r-1];
      if (nq > a[p] && a[p] > a[r]) {
        set<int>::iterator iter = s[r].lower_bound(a[p] + 1);
        if (iter == s[r].end()) continue;
        int nr = *iter;
        if (nr < nq)
          return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
      cin >> a[i];

    if (solve(a)) {
      cout << "YES\n";
      continue;
    }

    reverse(a.begin(), a.end());
    if (solve(a)) {
      cout << "YES\n";
      continue;
    }

    cout << "NO\n";
  }
  return 0;
}
