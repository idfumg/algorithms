#include "../../template.hpp"

int tab(const vi& arr, const int target) {
    int n = arr.size();
    int window = 0;
    int left = 0;
    int right = 0;
    int ans = INF;

    while (right < n) {
        window += arr[right++];
        while (window >= target) {
            ans = min(ans, right - left);
            window -= arr[left++];
        }
    }

    return ans == INF ? 0 : ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({2,3,1,2,4,3}, 7) << endl; // 2
    cout << tab({1,4,4}, 4) << endl; // 1
    cout << tab({1,1,1,1,1,1,1,1}, 11) << endl; // 0
    cout << tab({12,28,83,4,25,26,25,2,25,25,25,12}, 213) << endl; // 8
}
