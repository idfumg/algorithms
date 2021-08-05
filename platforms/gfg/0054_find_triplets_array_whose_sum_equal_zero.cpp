#include "../../template.hpp"

void FindTriplets1(vi arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << endl;
                }
            }
        }
    }
    cout << endl;
}

void FindTriplets2(vi arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = arr[i] + arr[j];
            if (binary_search(arr.begin() + j + 1, arr.end(), -sum)) {
                cout << arr[i] << ' ' << arr[j] << ' ' << -sum << endl;
            }
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    FindTriplets1({0, -1, 2, -3, 1}); // O(n^3)
    FindTriplets1({1, -2, 1, 0, 5});
    cout << endl;
    FindTriplets2({0, -1, 2, -3, 1}); // O(logn + n^2)
    FindTriplets2({1, -2, 1, 0, 5});
}
