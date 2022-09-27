#include <iostream>
#include <vector>

using namespace std;

vector<int> rightBigger(vector<int> &nums) {
    vector<int> res(nums.size(), 0);//������

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
    while (cin >> temp) //���κ���ĸΪ��������������q���ƽ���
    {
        nums.push_back(temp); //�������
    }
    vector<int> countR = rightBigger(nums);
    for (int i: countR) {
        cout << i << " ";
    }
    return 0;

}