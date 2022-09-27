#include <iostream>
#include <cmath>

using namespace std;

int backOne(int n, int cnt) {
    if (n == 1) {
        return cnt;
    }
    if (n % 2 == 0) {
        return backOne(n / 2, cnt + 1);
    } else {
        return min(backOne(n - 1, cnt + 1), backOne(n + 1, cnt + 1));
    }
}

int main() {
    int n = 0;
    cin >> n;
    cout << backOne(n, 0) << endl;
    return 0;

}