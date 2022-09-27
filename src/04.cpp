#include <iostream>

using namespace std;

int main() {
    int finalSum;
    cin >> finalSum;
    if (finalSum % 2 != 0) {
        cout << "[]" << endl;
        return 0;
    }
    int i = 2;
    cout << "[";
    while (2 * i < finalSum) {
        finalSum -= i;
        cout << i << ", ";
        i += 2;
    }
    cout << finalSum << "]" << endl;
    return 0;
}