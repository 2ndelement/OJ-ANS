#include <iostream>

void sort(int *arr, int size) {
    int i, j, k, tmp;
    for (i = 0; i < size - 1; i++) {
        k = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[k]) {
                k = j;
            }
        }
        tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }
}

int hIndex(int *array, int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] < i + 1) {
            return i;
        }
    }
    return len;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    sort(arr, n);
    std::cout << hIndex(arr, n) << std::endl;
}