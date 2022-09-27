#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n;
    auto v = vector<char>();
    do {
        v.push_back('A' + (n - 1) % 26);
        n = (n - 1) / 26;
    } while (n > 0);
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
}