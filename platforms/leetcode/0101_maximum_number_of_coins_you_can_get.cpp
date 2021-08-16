#include "../../template.hpp"

int tab(vi arr) {
    const int n = arr.size();
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = n - 1;
    int ans = 0;
    while (right - left + 1 >= 3) {
        --right;
        ans += arr[right--];
        ++left;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({2,4,1,2,7,8}) << endl; // 9
    cout << tab({2,4,5}) << endl; // 4
    cout << tab({9,8,7,6,5,1,2,3,4}) << endl; // 18
}
