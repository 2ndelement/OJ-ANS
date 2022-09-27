#include <iostream>

typedef unsigned long long ull;
#define N 1337
using namespace std;

ull pow(ull a, ull b, int mod) {
    ull res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ull a;
    int n;
    int *b = new int[n];
    cin >> a >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ull res = 1;
    for (int i = 0; i < n; i++) {
        res *= pow(a, b[i], N);
        res %= N;
        if (i != n - 1) {
            res = pow(res, 10, N);
        }
    }
    cout << res << endl;
    return 0;
}