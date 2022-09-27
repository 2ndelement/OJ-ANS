#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> t;
        arr[i] = t;
    }
    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }
    sort(arr, arr + n);
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > max) {
            max = arr[i] - arr[i - 1];
        }
    }
    cout << max << endl;
}