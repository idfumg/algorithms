#include "../../template.hpp"

int sol(vi values) {
    int n = values.size();
    int low = 0;
    int high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (values[low] < values[high]) return values[low];
        else if (values[mid] == values[high]) --high;
        else if (values[mid] > values[high]) low = mid + 1;
        else high = mid;
    }
    return values[low];
}

int main() { TimeMeasure _; __x();
    cout << sol({3,4,5,1,2}) << endl; // 1
    cout << sol({4,5,6,7,0,1,2}) << endl; // 0
    cout << sol({11,13,15,17}) << endl; // 11
    cout << sol({2,1}) << endl; // 1
}
