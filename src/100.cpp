#include <iostream>
#include <cmath>

using namespace std;

double sum(double *arr, int len) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return round(sum * 10) / 10;
}

bool can_get_24(double *arr, int len, int cnt) {
    if (cnt == 1) return round(sum(arr, len)) == 24;
    if (sum(arr, len) == 24) return true;
    for (int i = 0; i < len; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = 0; j < len; j++) {
            if (arr[j] == 0 || i == j) {
                continue;
            }
            double tmp = arr[j];
            arr[i] -= arr[j];
            arr[j] = 0;
            if (can_get_24(arr, len, cnt - 1)) {
                return true;
            }
            arr[i] += tmp;
            arr[j] = tmp;
            arr[i] *= arr[j];
            arr[j] = 0;
            if (can_get_24(arr, len, cnt - 1)) {
                return true;
            }
            arr[i] /= tmp;
            arr[j] = tmp;
            arr[i] += arr[j];
            arr[j] = 0;
            if (can_get_24(arr, len, cnt - 1)) {
                return true;
            }
            arr[i] -= tmp;
            arr[j] = tmp;
            arr[i] /= arr[j];
            arr[j] = 0;
            if (can_get_24(arr, len, cnt - 1)) {
                return true;
            }
            arr[i] *= tmp;
            arr[j] = tmp;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int len = 4;
    double arr[len];
    for (double &i: arr) {
        cin >> i;
    }
    cout << (can_get_24(arr, len, len) ? "true" : "false") << endl;
}