/*
ID: whitech1
TASK: combo
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
inline bool check(int a, int b, int n) {
	return (a-b+n)%n<=2 || (b-a+n)%n<=2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
	int n;
	cin >> n;
	int a[2][3];
	for(int i=0; i<2; i++) {
		for(int j=0; j<3; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	int cnt = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				for(int r=0; r<2; r++) {
					if(check(i,a[r][0],n) && check(j,a[r][1],n) && check(k,a[r][2],n)) {
						cnt++; break;
					}
				}
			}
		}
	}
	cout << cnt << "\n";
    return 0;
}
