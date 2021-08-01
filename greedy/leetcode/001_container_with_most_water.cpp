#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();
    int left = 0;
    int right = n - 1;
    int ans = 0;
    while (left < right) {
        const int area = min(arr[left], arr[right]) * (right - left);
        ans = max(ans, area);
        if (arr[left] <= arr[right]) ++left;
        else --right;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,8,6,2,5,4,8,3,7}) << endl; // 49
    cout << tab({1,1}) << endl; // 1
    cout << tab({4,3,2,1,4}) << endl; // 16
    cout << tab({1,2,1}) << endl; // 2
}
