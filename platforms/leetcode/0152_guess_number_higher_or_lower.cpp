#include "../../template.hpp"

int sol(const int n, const int key) {
    int low = 1, high = n;
    while (low <= high) {
        const int mid = low + (high - low) / 2;
        if (mid == key) return mid;
        else if (mid < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    cout << sol(10, 6) << endl; // 6
    cout << sol(1, 1) << endl; // 1
    cout << sol(2, 1) << endl; // 1
    cout << sol(2, 2) << endl; // 2
}
