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

int tab2(const vi& arr) {
    const int n = arr.size();
    deque<vi> mq;
    vi left(n);
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (not mq.empty() and arr[i] < arr[mq.back()[0]]) {
            count += mq.back()[1];
            mq.pop_back();
        }
        left[i] = count;
        mq.push_back({i, count});
    }
    mq.clear();
    vi right(n);
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (not mq.empty() and arr[i] <= arr[mq.back()[0]]) {
            count += mq.back()[1];
            mq.pop_back();
        }
        right[i] = count;
        mq.push_back({i, count});
    }
    uint64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += left[i] * right[i] * arr[i];
        ans %= MOD;
    }
    return ans;
}

uint64_t tab3(const vi& arr) {
    const int n = arr.size();

    deque<int> mq;
    vi left(n);
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (not mq.empty() and arr[i] < arr[mq.back()]) {
            count += left[mq.back()];
            mq.pop_back();
        }
        left[i] = count;
        mq.push_back(i);
    }

    mq.clear();
    vi right(n);
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (not mq.empty() and arr[i] <= arr[mq.back()]) { // <= - dont repeat
            count += right[mq.back()];
            mq.pop_back();
        }
        right[i] = count;
        mq.push_back(i);
    }

    uint64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += static_cast<uint64_t>(left[i]) * right[i] * arr[i];
        ans %= MOD;
    }
    return ans;
}

int tab4(const vi& arr) {
    const int n = arr.size();
    deque<int> mq;
    vi left(n);
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] < arr[mq.back()]) mq.pop_back();
        if (mq.empty()) left[i] = 0;
        else left[i] = mq.back() + 1;
        mq.push_back(i);
    }
    mq.clear();
    vi right(n);
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] <= arr[mq.back()]) mq.pop_back();
        if (mq.empty()) right[i] = n - 1;
        else right[i] = mq.back() - 1;
        mq.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arr[i] * (i - left[i] + 1) * (right[i] - i + 1);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4}) << endl; // 20
    cout << tab({4,3,2,1}) << endl; // 20
    cout << tab({3,1,2,4}) << endl; // 17
    cout << tab({11,81,94,43,3}) << endl; // 444
    cout << tab({71,55,82,55}) << endl; // 593
    cout << endl;
    cout << tab2({1,2,3,4}) << endl; // 20
    cout << tab2({4,3,2,1}) << endl; // 20
    cout << tab2({3,1,2,4}) << endl; // 17
    cout << tab2({11,81,94,43,3}) << endl; // 444
    cout << tab2({71,55,82,55}) << endl; // 593
    cout << endl;
    cout << tab3({1,2,3,4}) << endl; // 20
    cout << tab3({4,3,2,1}) << endl; // 20
    cout << tab3({3,1,2,4}) << endl; // 17
    cout << tab3({11,81,94,43,3}) << endl; // 444
    cout << tab3({71,55,82,55}) << endl; // 593
    cout << endl;
    cout << tab4({1,2,3,4}) << endl; // 20
    cout << tab4({4,3,2,1}) << endl; // 20
    cout << tab4({3,1,2,4}) << endl; // 17
    cout << tab4({11,81,94,43,3}) << endl; // 444
    cout << tab4({71,55,82,55}) << endl; // 593
}
