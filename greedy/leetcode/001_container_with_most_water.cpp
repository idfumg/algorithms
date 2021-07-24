#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();
    if (n < 2) return 0;
    int left = 0;
    int right = n - 1;
    int leftmax = arr[left];
    int rightmax = arr[right];
    int water = 0;
    while (left < right) {
        water = max(water, (right - left) * min(leftmax, rightmax));
        if (leftmax <= rightmax) {
            ++left;
            leftmax = max(leftmax, arr[left]);
        }
        else {
            --right;
            rightmax = max(rightmax, arr[right]);
        }
    }
    return water;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,8,6,2,5,4,8,3,7}) << endl; // 49
    cout << tab({1,1}) << endl; // 1
    cout << tab({4,3,2,1,4}) << endl; // 16
    cout << tab({1,2,1}) << endl; // 2
}
