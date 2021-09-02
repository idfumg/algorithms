#include "../../template.hpp"

int sol(const vi& arr) {
    const int n = arr.size();
    if (n < 3) return 0;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] <= arr[i - 1]) return 0;
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
            while (i < n - 1) {
                if (arr[i] <= arr[i + 1]) {
                    return 0;
                }
                ++i;
            }
            return 1;
        }
    }
    return 0;
}

int rec(const vi& arr, const int n, const int k) {
    if (n <= 0 and k == 1) return 1;
    if (n <= 0 and k == 0) return 0;
    if (k == 1 and arr[n] <= arr[n - 1]) return 0;
    if (k == 1) return rec(arr, n - 1, 1);
    if (n + 1 < arr.size() and arr[n] > arr[n - 1] and arr[n] > arr[n + 1]) return rec(arr, n, 1);
    if (arr[n] >= arr[n - 1]) return 0;
    return rec(arr, n - 1, 0);
}

int rec(const vi& arr) {
    if (arr.size() < 3) return 0;
    return rec(arr, arr.size() - 1, 0);
}

int main() { TimeMeasure _; __x();
    cout << sol({2,1}) << endl; // 0
    cout << sol({3,5,5}) << endl; // 0
    cout << sol({0,3,2,1}) << endl; // 1
    cout << sol({0,1,2,1,2}) << endl; // 0
    cout << sol({0,1,2,4,2,1}) << endl; // 1
    cout << sol({9,8,7,6,5,4,3,2,1,0}) << endl; // 0
    cout << sol({1,1,1,1,1,1,1,2,1}) << endl; // 0
    cout << sol({2,1,2,3,5,7,9,10,12,14,15,16,18,14,13}) << endl; // 0
    cout << endl;
    cout << rec({2,1}) << endl; // 0
    cout << rec({3,5,5}) << endl; // 0
    cout << rec({0,3,2,1}) << endl; // 1
    cout << rec({0,1,2,1,2}) << endl; // 0
    cout << rec({0,1,2,4,2,1}) << endl; // 1
    cout << rec({9,8,7,6,5,4,3,2,1,0}) << endl; // 0
    cout << rec({1,1,1,1,1,1,1,2,1}) << endl; // 0
    cout << rec({2,1,2,3,5,7,9,10,12,14,15,16,18,14,13}) << endl; // 0
}
