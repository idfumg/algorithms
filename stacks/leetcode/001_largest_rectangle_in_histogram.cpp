#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();
    stack<int> st;
    st.push(0);
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        while (not st.empty() and arr[st.top()] > arr[i]) {
            const int idx = st.top(); st.pop();
            if (st.empty()) ans = max(ans, arr[idx] * i);
            else ans = max({
                    ans,
                    arr[idx] * (i - idx), // extend forward element from the stack
                    arr[i] * (i - idx + 1) // extend backward current element
                });
        }
        st.push(i);
    }
    while (not st.empty()) {
        const int idx = st.top(); st.pop();
        if (st.empty()) ans = max(ans, arr[idx] * n);
        else ans = max(ans, arr[idx] * (n - idx));
    }
    return ans;
}

int tab2(const vi& arr) {
    int n = arr.size();

    deque<int> mq;

    vector<int> nearestleft(n);
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] <= arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) nearestleft[i] = -1;
        else nearestleft[i] = mq.back();
        mq.push_back(i);
    }

    vector<int> nearestright(n);
    mq.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] <= arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) nearestright[i] = n;
        else nearestright[i] = mq.back();
        mq.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int width = nearestright[i] - nearestleft[i] - 1;
        ans = max(ans, width * arr[i]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({2,1,5,6,2,3}) << endl; // 10
    cout << tab({2,4}) << endl; // 4
    cout << tab({1,1}) << endl; // 2
    cout << tab({2,1,2}) << endl; // 3
    cout << endl;
    cout << tab2({2,1,5,6,2,3}) << endl; // 10
    cout << tab2({2,4}) << endl; // 4
    cout << tab2({1,1}) << endl; // 2
    cout << tab2({2,1,2}) << endl; // 3
}
