#include <iostream>

#define MOD 1000000007
typedef long long ll;
using namespace std;

ll quick_pow(ll num, ll power, ll mod) {
    ll res = 1;
    num %= mod;
    while (power) {
        if (power & 1) {
            res = (res * num) % mod;
        }
        num = (num * num) % mod;
        power >>= 1;
    }
    return res;
}

ll getResult(int n) {
    ll max_num = (1ll << n) - 1;
    return max_num % MOD *
           quick_pow(max_num - 1, max_num / 2, MOD)
           % MOD;
}

int main() {
    ios_base::sync_with_stdio(true);
    int p;
    cin >> p;
    cout << getResult(p) << endl;
    return 0;
}