#include <iostream>
#include <string>
#include <stack>

using namespace std;

class mystack : public stack<char> {
public:
    char pop() {
        char result = stack<char>::top();
        stack<char>::pop();
        return result;
    }
};


bool trueOrFalse(string expression) {
    mystack nums, ops;
    for (auto it: expression) {
        switch (it) {
            case '|':
            case '&':
            case '!':
                ops.push(it);
                break;
            case 't':
            case 'f':
            case '(':
                nums.push(it);
                break;
            case ')':
                int tmp;
                char num;
                switch (ops.pop()) {
                    case '|':
                        tmp = 0;
                        while ((num = nums.pop()) != '(') {
                            tmp |= (num == 't');
                        }
                        break;
                    case '&':
                        tmp = 1;
                        while ((num = nums.pop()) != '(') {
                            tmp &= (num == 't');
                        }
                        break;
                    case '!':
                        while ((num = nums.pop()) != '(') {
                            tmp = (num != 't');
                        }
                        break;
                }
                nums.push(tmp ? 't' : 'f');


        }
    }
    return nums.pop() == 't';
}

int main() {

    string str;
    cin >> str;
    cout << trueOrFalse(str) << endl;
    return 0;

}