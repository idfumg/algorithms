#include "../../template.hpp"

int tab(const vi& arr) {
    int n = arr.size();
    deque<int> mq;
    vi left(n, -1);
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] <= arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) left[i] = -1;
        else left[i] = mq.back();
        mq.push_back(i);
    }
    vi right(n, n);
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] >= arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) right[i] = n;
        else right[i] = mq.back();
        mq.push_back(i);
    }
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (left[i] != -1 and right[i] != n) {
            return 1;
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4,5}) << endl; // 1
    cout << tab({5,4,3,2,1}) << endl; // 0
    cout << tab({2,1,5,0,4,6}) << endl; // 1
    cout << tab({20,100,10,12,5,13}) << endl; // 1
    cout << tab({1,2,1,3}) << endl; // 1
    cout << tab({1,5,0,4,1,3}) << endl; // 1
}
