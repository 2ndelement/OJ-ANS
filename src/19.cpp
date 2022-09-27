#include <iostream>
#include <vector>

using namespace std;

vector<int> rightBigger(vector<int> &nums) {
    vector<int> res(nums.size(), 0);//保存结果

    for (int i = 0; i < nums.size(); i++) {
        int cnt = 0;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                cnt++;
            }
        }
        res[i] = cnt;
    }
    return res;
}

int main() {
    vector<int> nums;
    int temp = 0;
    while (cin >> temp) //以任何字母为结束，输入中用q控制结束
    {
        nums.push_back(temp); //填充数据
    }
    vector<int> countR = rightBigger(nums);
    for (int i: countR) {
        cout << i << " ";
    }
    return 0;

}