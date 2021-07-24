#include "../../template.hpp"

int tab(const vi& arr) {
    int n = arr.size();
    stack<int> st;
    vi lower(n);
    for (int i = n - 1; i >= 0; --i) {
        while (not st.empty() and arr[st.top()] > arr[i]) st.pop();
        if (st.empty()) lower[i] = INF;
        else lower[i] = st.top();
        st.push(i);
    }
    int ans = 0;
    vi count(n);
    for (int i = n - 1; i >= 0; --i) {
        int low = lower[i];
        if (low == INF) count[i] = arr[i] * (n - i);
        else count[i] = count[low] + arr[i] * (low - i);
        ans += count[i];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4}) << endl; // 20
    cout << tab({4,3,2,1}) << endl; // 20
    cout << tab({3,1,2,4}) << endl; // 17
    cout << tab({11,81,94,43,3}) << endl; // 444
}
