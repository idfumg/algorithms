#include "../../template.hpp"

int sol(const vi& arr, const int n, const int k) {
    if (n <= 0) return k >= 0;
    if (arr[n] <= arr[n - 1]) {
        if (n == 1) return k > 0;
        if (arr[n] > arr[n - 2] and sol(arr, n - 2, k - 1)) return true;
        if (n < arr.size() - 1 and arr[n + 1] > arr[n - 1] and sol(arr, n - 1, k - 1)) return true;
        return n == arr.size() - 1 and sol(arr, n - 1, k - 1);
    }
    return sol(arr, n - 1, k);
}

int sol(const vi& arr) {
    return sol(arr, arr.size() - 1, 1);
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,10,5,7}) << endl; // 1
    cout << sol({2,3,1,2}) << endl; // 0
    cout << sol({1,1,1}) << endl; // 0
    cout << sol({1,2,3}) << endl; // 1
    cout << sol({105,924,32,968}) << endl; // 1
    cout << sol({512,867,904,997,403}) << endl; // 1
    cout << sol({100,21,100}) << endl; // 1
    cout << sol({915,444,500}) << endl; // 1
}
