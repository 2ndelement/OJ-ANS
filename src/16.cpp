#include <iostream>

#include <vector>

using namespace std;

int num_count(vector<int> nums, int num, int start, int end);

int effectiveSub(vector<int> nums);


int main() {

    vector<int> nums;
    int temp = 0;
    while (cin >> temp)     //�����ļ�д���ǣ�0 1 1 0 q����������κ���ĸ�������롣����q�������롣
    {
        nums.push_back(temp);     //�������
    }
    cout << effectiveSub(nums);
    return 0;

}

int num_count(vector<int> nums, int num, int start, int end) {
    int cnt = 0;
    if (end >= nums.size()) {
        end = nums.size() - 1;
    }
    for (int i = start; i < end + 1; i++) {
        if (nums[i] == num) {
            cnt++;
        }
    }
    return cnt;
}

int effectiveSub(vector<int> nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j + i < nums.size(); j++) {
            if (num_count(nums, 1, j, j + i) > num_count(nums, 0, j, j + i)) {
                cnt++;
            }
        }
    }
    return cnt;
}