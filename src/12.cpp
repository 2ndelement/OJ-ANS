#include <iostream>

using namespace std;

int hibonacci(int n);

int main() {

    int n = 0;
    cin >> n;

    cout << hibonacci(n) << endl;
    return 0;

}

int hibonacci(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        return hibonacci(n - 1) + hibonacci(n - 2) + hibonacci(n - 3);
    }
}