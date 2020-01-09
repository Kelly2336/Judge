/*
ID: whitech1
TASK: crypt1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool use[10];
inline int thd(int x) {return x/1000%10;}
inline int hun(int x) {return x/100%10;}
inline int ten(int x) {return x/10%10;}
inline int dig(int x) {return x%10;}
inline bool check2(int x) {
	return use[ten(x)] && use[dig(x)];
}
inline bool check3(int x) {
	return use[hun(x)] && check2(x);
}
inline bool check4(int x) {
	return use[thd(x)] && check3(x);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
	int n; cin >> n;
	for(int i=0, x; i<n; i++) {
		cin >> x;
		use[x] = true;
	}
	int ans = 0;
	for(int i=111; i<=999; i++) {
		if(!check3(i)) continue;
		for(int j=11; j<=99; j++) {
			if(!check2(j)) continue;
			int a = j%10 * i;
			int b = j/10 * i;
			int c = a + b*10;
			if(c>=10000) break;
			if(a>=1000 || b>= 1000) continue;
			if(check3(a) && check3(b) && check4(c)) ans++;
		}
	}
	cout << ans << "\n";
    return 0;
}
