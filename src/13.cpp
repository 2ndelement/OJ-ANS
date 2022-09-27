#include <iostream>

using namespace std;

int addSumOfN(int n);

int main() {

    int n = 0;
    cin >> n;
    cout << addSumOfN(n) << endl;
    return 0;
}

int addSumOfN(int n) {
    int sum = n;
    n && (sum += addSumOfN(n - 1));
    return sum;
}