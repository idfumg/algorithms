#include "../../template.hpp"

int tab(const vi& arr) {
    int n = arr.size();
    deque<int> mq;
    int prev = -INF;
    for (int i = n - 1; i >= 0; --i) {
        if (prev != -INF and arr[prev] > arr[i]) return true;
        while (not mq.empty() and arr[i] > arr[mq.back()]) {
            prev = mq.back();
            mq.pop_back();
        }
        mq.push_back(i);
    }
    return false;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4}) << endl; // 0
    cout << tab({3,1,4,2}) << endl; // 1
    cout << tab({-1,3,2,0}) << endl; // 1
    cout << tab({1,0,1,-4,-3}) << endl; // 0
    cout << tab({-2,1,1}) << endl; // 0
}
