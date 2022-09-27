#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string invert(string str) {
    for (char &i: str) {
        i = (i == '1' ? '0' : '1');
    }
    return str;
}

string reverse(string str) {
    reverse(str.begin(), str.end());
    return str;
}

string recursion(int n) {
    if (n == 1) {
        return "0";
    } else {
        string str = recursion(n - 1);
        return (str + "1" + reverse(invert(str)));
    }
}

int get_result(int n, int k) {
    return recursion(n)[k - 1] - '0';
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << get_result(n, k) << endl;
}