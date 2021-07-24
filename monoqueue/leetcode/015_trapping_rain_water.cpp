#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();

    if (n < 3) return 0;

    vi leftmax(n);
    leftmax[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        leftmax[i] = max(leftmax[i - 1], arr[i]);
    }

    vi rightmax(n);
    rightmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 1; --i) {
        rightmax[i] = max(rightmax[i + 1], arr[i]);
    }

    int water = 0;
    for (int i = 1; i < n - 1; ++i) {
        water += min(leftmax[i], rightmax[i]) - arr[i];
    }
    return water;
}

int main() { TimeMeasure _; __x();
    cout << tab({0,1,0,2,1,0,1,3,2,1,2,1}) << endl; // 6
    cout << tab({4,2,0,3,2,5}) << endl; // 9
    cout << tab({}) << endl; // 0
    cout << tab({4,2,3}) << endl; // 1
}
