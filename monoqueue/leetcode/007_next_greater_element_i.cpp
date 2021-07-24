#include "../../template.hpp"

vi tab(const vi& a, const vi& b) {
    int n = b.size();
    unordered_map<int, int> next_greater;
    deque<int> mq;
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and b[i] >= b[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) next_greater[b[i]] = -1;
        else next_greater[b[i]] = b[mq.back()];
        mq.push_back(i);
    }

    int m = a.size();
    vi ans(m);
    for (int i = 0; i < m; ++i) {
        ans[i] = next_greater[a[i]];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({4,1,2}, {1,3,4,2}) << endl; // -1,3,-1
    cout << tab({2,4}, {1,2,3,4}) << endl; // 3,-1
}
