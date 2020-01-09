/*
ID: whitech1
TASK: barn1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define maxs 205
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
	int M, S, C;
	cin >> M >> S >> C;
	vector<int> v(C+1);
	for(int i=1; i<=C; i++)
		cin >> v[i];
	sort(v.begin()+1, v.end());
	v[0] = v[1]-1;
	vector<int> cnt(M+1, 1);
	cnt[0] = S;
	for(int i=2; i<=C; i++)
		for(int j=M; j>0; j--)
			cnt[j] = min( v[i] - v[i-1] + cnt[j], cnt[j-1] + 1);
	cout << cnt[M] << "\n";
    return 0;
}
//這題應該用greedy才對O(ClgC)，但還是用了複雜度高的dp O(CM)
