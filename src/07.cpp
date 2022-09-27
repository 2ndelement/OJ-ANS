#include <iostream>

using namespace std;

int fun(int n, int k) {
    if (n % 2 == 1 && k % 2 == 0) {
        return -1;
    }
    int res = 0;
    while (true) {
        res++;
        n -= k;
        if (n < 0) {
            return -1;
        }
        if (n % 10 == 0) {
            return res;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << fun(n, k) << endl;
    return 0;
}