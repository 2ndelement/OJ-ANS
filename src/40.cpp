#include<iostream>

using namespace std;


int main() {
    int n, m;
    int t;
    cin >> n >> m;
    int res = 0;
    int ***arr;
    for (int i = 0; i < 2; i++) {
        arr = new int **[n];
        for (int j = 0; j < 2; j++) {
            arr[j] = new int *[m + 1];
            for (int k = 0; k < m + 1; k++) {
                arr[j][k] = new int[3]();
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> t;
            if (t) {
                arr[i % 2][j][0] = arr[i % 2][j - 1][0] + 1;
                arr[i % 2][j][1] = arr[(i - 1) % 2][j][1] + 1;
                arr[i % 2][j][2] = arr[(i - 1) % 2][j - 1][2] + 1;
                for (int k = 0; k <= 2; k++) {
                    res = max(arr[i % 2][j][k], res);
                }
            } else {
                for (int k = 0; k <= 2; k++) {
                    arr[i % 2][j][k] = 0;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}