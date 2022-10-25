#include <bits/stdc++.h>

using namespace std;

int min_cost(int **costs, int n) {
    int **dp = new int*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[3];
    }
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    int ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int **costs = new int *[n];
    for (int i = 0; i < n; i++) {
        costs[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            cin >> costs[i][j];
        }
    }
    cout << min_cost(costs, n) << endl;
    return 0;
}