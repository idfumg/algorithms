#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();
    vector<uint64_t> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    const auto get_sum = [&prefix](const int i, const int j) {
        assert(i >= 0 and i <= j);
        return prefix[j + 1] - prefix[i];
    };
    vi leftmax(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (not st.empty() and arr[st.top()] >= arr[i]) st.pop();
        if (st.empty()) leftmax[i] = 0;
        else leftmax[i] = st.top() + 1;
        st.push(i);
    }
    vi rightmax(n);
    st = stack<int>{};
    for (int i = n - 1; i >= 0; --i) {
        while (not st.empty() and arr[st.top()] >= arr[i]) st.pop();
        if (st.empty()) rightmax[i] = n - 1;
        else rightmax[i] = st.top() - 1;
        st.push(i);
    }
    uint64_t ans = 0;
    const int M = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
        ans = max({ans, arr[i] * get_sum(leftmax[i], rightmax[i])});
    }
    return ans % M;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,2}) << endl; // 14
    cout << tab({2,3,3,1,2}) << endl; // 18
    cout << tab({3,1,5,6,4,2}) << endl; // 60
    cout << tab({1,1,3,2,2,2,1,5,1,5}) << endl; // 25
    cout << tab({2,5,4,2,4,5,3,1,2,4}) << endl; // 50
}
