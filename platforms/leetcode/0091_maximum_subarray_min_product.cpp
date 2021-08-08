#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();

    deque<int> mq;
    vi left(n);
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] <= arr[mq.back()]) mq.pop_back();
        if (mq.empty()) left[i] = -1;
        else left[i] = mq.back();
        mq.push_back(i);
    }

    mq.clear();
    vi right(n);
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] <= arr[mq.back()]) mq.pop_back();
        if (mq.empty()) right[i] = n;
        else right[i] = mq.back();
        mq.push_back(i);
    }

    vector<uint64_t> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    uint64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        const ll cost = prefix[right[i]] - prefix[left[i] + 1];
        ans = max(ans, (uint64_t)cost * arr[i]);
    }
    constexpr int M = 1e9 + 7;
    return ans % M;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,2}) << endl; // 14
    cout << tab({2,3,3,1,2}) << endl; // 18
    cout << tab({3,1,5,6,4,2}) << endl; // 60
    cout << tab({1,1,3,2,2,2,1,5,1,5}) << endl; // 25
    cout << tab({2,5,4,2,4,5,3,1,2,4}) << endl; // 50
}
