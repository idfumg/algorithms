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
    cout << sol({1,3,5}) << endl; // 1
    cout << sol({2,2,2,0,1}) << endl; // 0
    cout << sol({3,1,3}) << endl; // 1
    cout << sol({3,3,1,3}) << endl; // 1
    cout << sol({1,3,3}) << endl; // 1
    cout << sol({3,1,3,3}) << endl; // 1
    cout << sol({2,0,1,1,1}) << endl; // 0
    cout << sol({2,2,0,1,1,2}) << endl; // 0
    cout << sol({1,1}) << endl; // 1
}
