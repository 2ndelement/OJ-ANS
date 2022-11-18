#include <iostream>
#include <vector>

using namespace std;

int swing_sequence(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int res = 2;
    int diff = nums[1] - nums[0];
    int i = 2;
    while (i < n) {
        if ((nums[i] - nums[i - 1]) * diff < 0) {
            diff = nums[i] - nums[i - 1];
            res++;
        }
        i++;
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << swing_sequence(nums);
    return 0;

}