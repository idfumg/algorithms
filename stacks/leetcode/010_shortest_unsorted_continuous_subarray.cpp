#include "../../template.hpp"

int tab(const vi& arr) {
    int n = arr.size();

    deque<int> mq;
    vi right(n);
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] > arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) right[i] = n;
        else right[i] = mq.back();
        mq.push_back(i);
    }

    vi left(n);
    mq.clear();
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] < arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) left[i] = -1;
        else left[i] = mq.back();
        mq.push_back(i);
    }

    int low = -1;
    for (int i = 0; i < n; ++i) {
        if (left[i] != i - 1 or right[i] != i + 1) {
            low = i;
            break;
        }
    }

    int high = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (left[i] != i - 1 or right[i] != i + 1) {
            high = i;
            break;
        }
    }

    if (low == -1 or high == -1 or low >= high) return 0;

    int mini = INF;
    int maxi = -INF;
    for (int i = low; i <= high; ++i) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    while (low - 1 >= 0 and arr[low - 1] > mini) --low;
    while (high + 1 < n and arr[high + 1] < maxi) ++high;

    return high - low + 1;
}

int main() { TimeMeasure _; __x();
    cout << tab({2,6,4,8,10,9,15}) << endl; // 5
    cout << tab({1,2,3,4}) << endl; // 0
    cout << tab({4,3,2,1}) << endl; // 4
    cout << tab({1}) << endl; // 0
    cout << tab({1,3,2,2,2}) << endl; // 4
    cout << tab({2,3,3,2,4}) << endl; // 3
    cout << tab({1,1}) << endl; // 0
    cout << tab({1,2,4,5,3}) << endl; // 3
}
