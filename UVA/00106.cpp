#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int first[MAX], num[MAX], ans[MAX], p[MAX];
inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
inline bool coprime(int x, int y, int z) {
    return gcd(gcd(x, y), z) == 1;
}
int main() {
    fill(first, first + MAX, MAX);
    for (int m = 2; m < 1000; m++)
        for (int n = (m & 1) + 1; n < m; n += 2) {
            if (gcd(m, n) != 1) continue;
            int x = m * m - n * n;
            int y = 2 * m * n;
            int z = m * m + n * n;
            if (z >= MAX) break;
            if (coprime(x, y, z)) {
                p[z]++;
                for(int k = MAX / z; k >= 1; k--) {
                    int xx = x * k;
                    int yy = y * k;
                    int zz = z * k;
                    first[xx] = min(first[xx], zz);
                    first[yy] = min(first[yy], zz);
                    first[zz] = zz;
                }
            }
        }
    for(int i = 1; i <= MAX; i++)
        p[i] += p[i - 1], num[first[i]]++;
    ans[1] = 1;
    for (int i = 2; i <= MAX; i++)
        ans[i] = ans[i - 1] + 1 - num[i];
    int N;
    while (scanf("%d", &N) == 1)
        printf("%d %d\n", p[N], ans[N]);
    return 0;
}
