#include "../../template.hpp"

void sol_(vi& arr) {
    const int n = arr.size();
    if (n <= 1) return;
    int left = 0;
    int mid = 0;
    int right = n - 1;
    while (mid <= right) {
        if (arr[mid] == 0) swap(arr[left++], arr[mid++]);
        else if (arr[mid] == 2) swap(arr[mid], arr[right--]);
        else ++mid;
    }
}

vi sol(vi arr) {
    sol_(arr);
    return arr;
}

int main() { TimeMeasure _; __x();
    cout << sol({2,0,2,1,1,0}) << endl; // 0,0,1,1,2,2
    cout << sol({2,0,1}) << endl; // 0,1,2
    cout << sol({0}) << endl; // 0
    cout << sol({1}) << endl; // 1
    cout << sol({}) << endl; //
}
