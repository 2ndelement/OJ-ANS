#include <iostream>
#include <vector>

using namespace std;


int minSelect(vector<int> &nums, int n, int sum, int depth, int left, int right) {
    if (sum == n) {
        return depth;
    }
    if (left == right) {
        return INT32_MAX;
    }
    return min(minSelect(nums, n, sum + nums[left], depth + 1, left + 1, right),
               minSelect(nums, n, sum + nums[right], depth + 1, left, right - 1));
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int temp = 0;
    while (cin >> temp) {
        nums.push_back(temp); //Ìî³äÊı¾İ
    }
    int res = minSelect(nums, n, 0, 0, 0, nums.size() - 1);
    cout << (res == INT32_MAX ? -1 : res) << endl;
    return 0;

}