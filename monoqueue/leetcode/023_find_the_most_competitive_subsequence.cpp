#include "../../template.hpp"

vi tab(const vi& arr, int k) {
    int n = arr.size();
    deque<int> mq;
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] < arr[mq.back()] and mq.size() + n - i - 1 >= k) {
            mq.pop_back();
        }
        mq.push_back(i);
    }
    vi res(k, 0);
    for (int i = 0; i < k; ++i) {
        res[i] = arr[mq[i]];
    }
    return res;
}

int main() { TimeMeasure _; __x();
    cout << tab({3,5,2,6}, 2) << endl; // 2,6
    cout << tab({2,4,3,3,5,4,9,6}, 4) << endl; // 2,3,3,4
    cout << tab({71,18,52,29,55,73,24,42,66,8,80,2}, 3) << endl; // 8, 80, 2
}
