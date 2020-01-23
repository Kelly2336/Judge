#include<bits/stdc++.h>
using namespace std;

#define INF 1000

inline bool match(char a, char b) {
	return ( a == '(' && b == ')' ) || ( a == '[' && b == ']' );
}

int countDp(const string &s, vector<vector<int>> &dp, int i, int j) {
	if (dp[i][j] != INF)
		return dp[i][j];
	if (i > j) {
		dp[i][j] = 0;
	} else if (i == j) {
		dp[i][j] = 1;
	} else {
		if (match(s[i], s[j])) {
			dp[i][j] = min(dp[i][j], countDp(s, dp, i+1, j-1));
		}
		for (int k = i; k < j; k++) {
			dp[i][j] = min(dp[i][j], countDp(s, dp, i, k) + countDp(s, dp, k+1, j));
		}
	}
	return dp[i][j];
}

string backTrack(const string &s, vector<vector<int>> &dp, int i, int j) {
	if (i > j) return "";
	if (i == j) {
		if (s[i] == '(' || s[i] == ')') return "()";
		return "[]";
	}
	if (match(s[i], s[j]) && dp[i][j] == dp[i+1][j-1])
		return s[i] + backTrack(s, dp, i+1, j-1) + s[j];
	for (int k = i; k < j; k++)
		if (dp[i][j] == dp[i][k] + dp[k+1][j])
			return backTrack(s, dp, i, k) + backTrack(s, dp, k+1, j);
}

inline string solve(const string &s) {
    if (s == "") return s;
	int len = s.length();
	vector<vector<int>> dp(len, vector<int>(len, INF));
	countDp(s, dp, 0, len-1);
	return backTrack(s, dp, 0, len-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string buff;
	getline(cin, buff);
	while (t--) {
		string in;
		getline(cin, in);
		getline(cin, in);
		cout << solve(in) << "\n";
		if (t) cout << "\n";
	}
	return 0;
}
