#include <iostream>

using namespace std;

char couples[][2] = {{'0', '0'},
                     {'1', '1'},
                     {'6', '9'},
                     {'8', '8'},
                     {'9', '6'}};

bool compare(const string &a, const string &b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
    }
    return a.size() <= b.size();
}

void recurse(const string& low, const string& high, const string &current, int &res) {
    if (compare(low, current) && compare(current, high)) {
        if (current.length() == 1 || current[0] != '0') {
            res++;
        }
    }
    if (current.length() + 2 > high.length()) {
        return;
    }
    for (char *couple: couples) {
        recurse(low, high, couple[0] + current + couple[1], res);
    }
}

int count(const string& low, const string& high) {
    int res = 0;
    recurse(low, high, "", res);
    recurse(low, high, "0", res);
    recurse(low, high, "1", res);
    recurse(low, high, "8", res);
    return res;
}

int main() {
    string low, high;
    cin >> low >> high;
    cout << count(low, high) << endl;
    return 0;
}