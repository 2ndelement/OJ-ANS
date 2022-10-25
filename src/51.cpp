#include <bits/stdc++.h>

using namespace std;

int PO151(vector<int> &cost, vector<int> &value, int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < cost.size(); i++) {
        for (int j = n; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
        }
    }
    return dp[n];
}

int main() {
    int n, m;
    vector<int> c, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int cost, value;
        cin >> cost >> value;
        c.push_back(cost);
        v.push_back(value);
    }
    cout << PO151(c, v, n) << endl;
    return 0;
}