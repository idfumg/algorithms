#include "../../template.hpp"

int sol(vvi arr, int left, const int right) {
    sort(arr.begin(), arr.end(), [](const vi& a, const vi& b){
        return a[1] < b[1];
    });
    for (const vi& interval : arr) {
        if (interval[0] <= left and interval[1] >= left) {
            left += interval[1] - left + 1;
        }
    }
    return left > right;
}

int main() { TimeMeasure _; __x();
    cout << sol({{1,2},{3,4},{5,6}}, 2, 5) << endl; // 1
    cout << sol({{1,10},{10,20}}, 21, 21) << endl; // 0
    cout << sol({{36,50},{14,28},{4,31},{24,37},{13,36},{27,33},{23,32},{23,27},{1,35}}, 35, 40) << endl; // 1
}
