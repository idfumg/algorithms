#include "../../template.hpp"

vi tab(const vi& arr) {
    const int n = arr.size();
    deque<int> mq;
    vi right(n);
    for (int i = 2 * n - 1; i >= 0; --i) {
        const int idx = i % n;
        while (not mq.empty() and arr[idx] >= arr[mq.back()]) mq.pop_back();
        if (mq.empty()) right[idx] = -1;
        else right[idx] = arr[mq.back()];
        mq.push_back(idx);
    }
    return right;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,1}) << endl; // 2,-1,2
    cout << tab({1,2,3,4,3}) << endl; // 2,3,4,-1,4
}
