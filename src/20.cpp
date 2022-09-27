#include <iostream>

using namespace std;

string translateNumber(int num) {
    string result;
    if (num == 0) {
        return "Zero ";
    }
    if (num < 0) {
        result += "Minus ";
        num = -num;
    }
    if (num >= 1000000000) {
        result += translateNumber(num / 1000000000) + "Billion ";
        num %= 1000000000;
    }
    if (num >= 1000000) {
        result += translateNumber(num / 1000000) + "Million ";
        num %= 1000000;
    }
    if (num >= 1000) {
        result += translateNumber(num / 1000) + "Thousand ";
        num %= 1000;
    }
    if (num >= 100) {
        result += translateNumber(num / 100) + "Hundred ";
        num %= 100;
    }
    if (num >= 20) {
        switch (num / 10) {
            case 2:
                result += "Twenty ";
                break;
            case 3:
                result += "Thirty ";
                break;
            case 4:
                result += "Forty ";
                break;
            case 5:
                result += "Fifty ";
                break;
            case 6:
                result += "Sixty ";
                break;
            case 7:
                result += "Seventy ";
                break;
            case 8:
                result += "Eighty ";
                break;
            case 9:
                result += "Ninety ";
                break;
        }
        num %= 10;
    }
    if (num >= 10) {
        switch (num) {
            case 10:
                result += "Ten ";
                break;
            case 11:
                result += "Eleven ";
                break;
            case 12:
                result += "Twelve ";
                break;
            case 13:
                result += "Thirteen ";
                break;
            case 14:
                result += "Fourteen ";
                break;
            case 15:
                result += "Fifteen ";
                break;
            case 16:
                result += "Sixteen ";
                break;
            case 17:
                result += "Seventeen ";
                break;
            case 18:
                result += "Eighteen ";
                break;
            case 19:
                result += "Nineteen ";
        }
    }
    if (num >= 1 && num <= 9) {
        switch (num) {
            case 1:
                result += "One ";
                break;
            case 2:
                result += "Two ";
                break;
            case 3:
                result += "Three ";
                break;
            case 4:
                result += "Four ";
                break;
            case 5:
                result += "Five ";
                break;
            case 6:
                result += "Six ";
                break;
            case 7:
                result += "Seven ";
                break;
            case 8:
                result += "Eight ";
                break;
            case 9:
                result += "Nine ";
                break;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    string result = translateNumber(n);
    result = result.substr(0, result.length() - 1);
    cout << result << endl;
    return 0;

}