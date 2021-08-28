#include "../../template.hpp"

int sol(const int n, const int bad) {
    int low = 1, high = n;
    while (low <= high) {
        const int mid = low + (high - low) / 2;
        if (mid == bad) return mid;
        else if (mid < bad) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() { TimeMeasure _; __x();
    cout << sol(5, 4) << endl; // 4
    cout << sol(1, 1) << endl; // 1
}
