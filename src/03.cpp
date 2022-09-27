#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i / 7 + 1 + i % 7;
    }
    cout << sum << endl;
}