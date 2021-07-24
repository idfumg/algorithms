#include "../../template.hpp"

vi tab(const vi& arr) {
    int n = arr.size();
    vi elems(2 * n);
    deque<int> mq;
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i % n] >= arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) elems[i] = -1;
        else elems[i] = arr[mq.back()];
        mq.push_back(i % n);
    }
    return vi(elems.begin(), elems.begin() + n);
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,1}) << endl; // 2,-1,2
    cout << tab({1,2,3,4,3}) << endl; // 2,3,4,-1,4
}
