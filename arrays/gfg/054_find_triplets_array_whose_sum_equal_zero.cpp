#include "../../template.hpp"

int LowerBound(vi arr, int from, int key) {
    int n = arr.size(), low = from, high = n - 1;
    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key) low = mid + 1;
        else high = mid;
    }
    return low;
}

void FindTriplets(vi arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int x = -(arr[i] + arr[j]);
            int idx = LowerBound(arr, j + 1, x);
            if (arr[idx] == x) {
                cout << arr[i] << ' ' << arr[j] << ' ' << x << endl;
            }
        }
    }
}

int main() { TimeMeasure _;
    FindTriplets({0, -1, 2, -3, 1});
    FindTriplets({1, -2, 1, 0, 5});
}
