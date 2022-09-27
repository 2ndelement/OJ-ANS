#include <iostream>

using namespace std;

int count(int n) {
    int sum = 0;
    for (long long k = 1; k <= n; k *= 10) {
        long long i = k;
        sum += (n / (i * 10)) * i + min(max((n % (i * 10)) - i + 1, 0LL), i);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}