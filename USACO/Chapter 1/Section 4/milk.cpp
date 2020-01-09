/*
ID: whitech1
TASK: milk
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define p first
#define a second
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pii> v(m);
    for(int i=0; i<m; i++)
        cin >> v[i].p >> v[i].a;
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=0; i<m && n; i++) {
        if(n<v[i].a) v[i].a = n;
        sum += v[i].a * v[i].p;
        n -= v[i].a;
    }
    cout << sum << "\n";
    return 0;
}
