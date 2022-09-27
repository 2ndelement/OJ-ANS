#include <iostream>

using namespace std;

int fun(int n) {
    double x = n;
    int res = 1;
    for (int i = 2; i < n; i++) {
        double y = x / i;
        if (y - i / 2 <= 0) {
            break;
        }
        if (i % 2 == 0) {
            if (y - (int) y == 0.5) {
                res++;
            }
        } else {
            if (y == (int) y) {
                res++;
            }
        }

    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}