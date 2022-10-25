#include<bits/stdc++.h>

using namespace std;

int main() {
    const int N = 1e4 + 5, M = 1e7 + 5;
    long long n, m, w[N], v[N];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> w[i] >> v[i];
    }
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
        for (int j = w[i]; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}