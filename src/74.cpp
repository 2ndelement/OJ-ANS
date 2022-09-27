#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    return a + b < b + a;
}

void get_result(vector<int> arr) {
    vector<string> strs;
    for (auto num: arr) {
        strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), compare);
    for (const auto &str: strs) {
        cout << str;
    }
    cout << endl;
}

int main() {

    int n, t;
    vector<int> a;
    cin >> n;
    while (n--) {
        cin >> t;
        a.push_back(t);
    }
    get_result(a);
    return 0;
}