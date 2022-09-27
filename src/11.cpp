#include <iostream>

using namespace std;

bool fun(int n, int k) {
    if (k == 0) {
        return false;
    }
    if (n > 0 && k == 1) {
        return true;
    }
    if (k > 0 && n < 0) {
        return false;
    }
    while (n / k > 0) {
        if (n % k != 0) {
            return false;
        }
        n /= k;
    }
    if (n == 1) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << fun(n, k) << endl;
}