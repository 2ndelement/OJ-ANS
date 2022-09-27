#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recursion(int bitmask, int n, vector<int> &nums) {
    if (!bitmask) {
        for (int i: nums) {
            cout << i;
        }
        cout << endl;
        return;
    }
    for (int i = 1; i < n + 1; i++) {
        if (bitmask & (1 << (i - 1))) {
            nums.push_back(i);
            recursion(bitmask & ~(1 << (i - 1)), n, nums);
            nums.pop_back();
        }
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int bitmask = (1 << n) - 1;
    recursion(bitmask, n, nums);
    return 0;
}