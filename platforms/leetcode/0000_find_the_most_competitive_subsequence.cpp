#include "../../template.hpp"

vi sol(vi elems, int k) {
    int n = elems.size();
    deque<int> mq;
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and elems[i] < mq.back() and mq.size() - 1 + n - i >= k) {
            mq.pop_back();
        }
        mq.push_back(elems[i]);
    }
    while (mq.size() > k) mq.pop_back();
    return vi(mq.begin(), mq.end());
}

int main() { TimeMeasure _; __x();
    cout << sol({3,5,2,6}, 2) << endl; // 2,6
    cout << sol({2,4,3,3,5,4,9,6}, 4) << endl; // 2,3,3,4
    cout << sol({71,18,52,29,55,73,24,42,66,8,80,2}, 3) << endl; // 8, 80, 2
    cout << sol({1,1,1,1,1,1,1,1,0,0}, 5) << endl; // 1,1,1,0,0
}
