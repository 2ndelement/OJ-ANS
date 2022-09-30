#include <bits/stdc++.h>

using namespace std;

bool PO157(string s, vector<string> &wordDict) {
    int len = s.length();
    bool *dp = new bool[len + 1]();
    dp[0] = true;
    for (int i = 0; i < len; i++) {
        if (dp[i]) {
            for (int j = i; j < len; j++) {
                if (find(wordDict.begin(), wordDict.end(), s.substr(i, j - i + 1)) != wordDict.end()) {
                    dp[j + 1] = true;
                }
            }
        }
    }
    return dp[len];
}

int main() {
    int n;
    string a;
    vector<string> words;
    cin >> a;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    cout << (PO157(a, words) ? "True" : "False") << endl;
    return 0;
}