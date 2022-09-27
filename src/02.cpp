#include <iostream>

using namespace std;

int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}