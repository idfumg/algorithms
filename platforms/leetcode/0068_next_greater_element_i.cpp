#include "../../template.hpp"

vi tab(const vi& a, const vi& b) {
    const int m = a.size();
    const int n = b.size();

    deque<int> mq;
    unordered_map<int, int> idx;
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and b[i] > b[mq.back()]) mq.pop_back();
        if (mq.empty()) idx[b[i]] = -1;
        else idx[b[i]] = b[mq.back()];
        mq.push_back(i);
    }

    vi ans(m);
    for (int i = 0; i < m; ++i) {
        ans[i] = idx[a[i]];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({4,1,2}, {1,3,4,2}) << endl; // -1,3,-1
    cout << tab({2,4}, {1,2,3,4}) << endl; // 3,-1
}
