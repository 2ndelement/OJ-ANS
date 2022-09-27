#include <iostream>
#include <stack>

using namespace std;

char caculateRes(string str);

int main() {
    string str;
    cin >> str;
    cout << caculateRes(str) << endl;
    return 0;

}

char caculateRes(string str) {
    stack<char> stack;
    for (auto it = str.rbegin(); it != str.rend(); it++) {
        if (*it == ':') {
            stack.push(*(++it));
        } else if (*it == '?') {
            auto tmp = stack.top();
            stack.pop();
            if (*(++it) == 'T') {
                stack.pop();
                stack.push(tmp);
            }
        } else {
            stack.push(*it);
        }
    }
    return stack.top();
}