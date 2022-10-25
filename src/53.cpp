#include <bits/stdc++.h>

using namespace std;

int max_length(int **dp, vector<vector<int>> matrix, const int &i, const int &j) {
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    int res = 0;
    if (i > 0) {
        if (matrix[i - 1][j] < matrix[i][j]) {
            res = max(max_length(dp, matrix, i - 1, j), res);
        }
    }
    if (j > 0) {
        if (matrix[i][j - 1] < matrix[i][j]) {
            res = max(max_length(dp, matrix, i, j - 1), res);
        }
    }
    if (i < matrix.size() - 1) {
        if (matrix[i + 1][j] < matrix[i][j]) {
            res = max(max_length(dp, matrix, i + 1, j), res);
        }
    }
    if (j < matrix[0].size() - 1) {
        if (matrix[i][j + 1] < matrix[i][j]) {
            res = max(max_length(dp, matrix, i, j + 1), res);
        }
    }
    return res + 1;
}

int PO153(vector<vector<int>> &matrix) {
    int **dp = new int *[matrix.size()];
    for (int i = 0; i < matrix.size(); i++) {
        dp[i] = new int[matrix[0].size()]();
    }
    int res = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            dp[i][j] = max_length(dp, matrix, i, j);
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    int n, m, t;
    vector<vector<int>> matrix;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> mat;
        for (int j = 0; j < m; j++) {
            cin >> t;
            mat.push_back(t);
        }
        matrix.push_back(mat);
    }
    cout << PO153(matrix) << endl;
    return 0;

}