#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const char *fun(int n) {
    if (n == 1) return "true";
    set<string> s;
    for (int i = 1; i < 32; i++) {
        string str = to_string(1 << i);
        sort(str.begin(), str.end());
        s.insert(str);
    }
    string str = to_string(n);
    sort(str.begin(), str.end());
    return s.find(str) != s.end() ? "true" : "false";
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}