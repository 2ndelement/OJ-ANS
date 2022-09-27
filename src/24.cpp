#include<iostream>

using namespace std;
int index = 0, a[2000];
bool isEnd = false;

bool judgeBST(int start, int end) {
    if (start >= end) return true;
    int mid = end;
    for (int i = start; i < end; i++) {
        if (a[i] > a[end]) {
            mid = i;
            break;
        }
    }
    if (mid == end) return judgeBST(start, end - 1);
    for (int i = mid; i < end; i++) {
        if (a[i] < a[end]) return false;
    }
    if (start == mid) return judgeBST(start, end - 1);
    return judgeBST(start, mid - 1) && judgeBST(mid, end - 1);
}


int read() {
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    int ret = 0;
    while (ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    if (ch == ']') isEnd = true;
    return ret;
}

int main() {
    while (!isEnd) a[++index] = read();
    puts(judgeBST(1, index) ? "true" : "false");
}