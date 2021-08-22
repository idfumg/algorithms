#include "../../template.hpp"

vi sol(vi arr) {
    const int n = arr.size();
    int left = 0;
    int right = n - 1;
    while (left < right) {
        if (arr[left] >= 0) swap(arr[left], arr[right--]);
        else ++left;
    }
    return arr;
}

int main() { TimeMeasure _; __x();
    cout << sol({-12, 11, -13, -5, 6, -7, 5, -3, -6}) << endl; // -12 -6 -13 -5 -3 -7 5 6 11
}
