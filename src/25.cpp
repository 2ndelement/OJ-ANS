#include <iostream>

#define N 1000000007
using namespace std;

long long pow(long long a, long long b, int mod) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long get_good_divisor(int n) {
    if (n <= 3) {
        return n;
    }
    int a = n / 3;
    int b = n % 3;
    if (b == 1) {
        return pow(3, a - 1, N) * 4ll % N;
    } else if (b == 2) {
        return pow(3, a, N) * 2ll % N;
    } else {
        return pow(3, a, N);
    }
}

int main() {
    int p;
    cin >> p;
    cout << get_good_divisor(p) << endl;
    return 0;
}