#include "../../template.hpp"

int SearchInRotatedAndSorted(vi arr, int target) {
    int n = arr.size(), low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] >= arr[0] and target < arr[0]) low = mid + 1;
        else if (arr[mid] < arr[0] and target >= arr[0]) high = mid - 1;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return - 1;
}

int main() { TimeMeasure _;
    vi arr1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    vi arr2 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    vi arr3 = {30, 40, 50, 10, 20};
    vi arr4 = {10, 1, 2, 3, 5, 6, 7, 8, 9};
    vi arr5 = {1, 2, 3, 5, 6, 7, 8, 9};
    vi arr6 = {1, 2};
    vi arr7 = {1};
    vi arr8 = {};

    assert(SearchInRotatedAndSorted({5, 6, 7, 8, 9, 10, 1, 2, 3}, 3) == 8);
    assert(SearchInRotatedAndSorted({5, 6, 7, 8, 9, 10, 1, 2, 3}, 10) == 5);
    assert(SearchInRotatedAndSorted({5, 6, 7, 8, 9, 10, 1, 2, 3}, 7) == 2);
    assert(SearchInRotatedAndSorted({5, 6, 7, 8, 9, 10, 1, 2, 3}, 30) == -1);
    assert(SearchInRotatedAndSorted({30, 40, 50, 10, 20}, 10) == 3);
    assert(SearchInRotatedAndSorted({10, 1, 2, 3, 5, 6, 7, 8, 9}, 10) == 0);
    assert(SearchInRotatedAndSorted({1, 2, 3, 5, 6, 7, 8, 9}, 3) == 2);
    assert(SearchInRotatedAndSorted({1, 2}, 2) == 1);
    assert(SearchInRotatedAndSorted({1}, 1) == 0);
    assert(SearchInRotatedAndSorted({}, 1) == -1);
    assert(SearchInRotatedAndSorted({5, 1, 2, 3, 4}, 1) == 1);
}
