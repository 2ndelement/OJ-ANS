#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int fac(int n) {
    if (n == 0) {
        return 1;
    }
    int res = 1;
    for (int i = 2; i < n + 1; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    vector<int> num_list;
    for (int i = 0; i < n; i++) {
        num_list.push_back(i + 1);
        int tmp = fac(n - i - 1);
        int index = ceil(k / (float) tmp) - 1;
        nums.push_back(index > 0 ? index : 0);
        k %= tmp;
        if (k == 0) {
            k = tmp;
        }
    }
    for (int &i: nums) {
        cout << num_list[i];
        num_list.erase(num_list.begin() + i);
    }
    cout << endl;
    return 0;

}