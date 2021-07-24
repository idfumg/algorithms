#include "../../template.hpp"

vi tab(const vi& arr) {
    const int n = arr.size();
    vi ans(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (not st.empty() and arr[st.top()] < arr[i]) {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vi tab2(const vi& arr) {
    const int n = arr.size();
    vi ans(n);
    deque<int> mq;
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] >= arr[mq.back()]) {
            mq.pop_back();
        }
        if (mq.empty()) ans[i] = 0;
        else ans[i] = mq.back() - i;
        mq.push_back(i);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({73,74,75,71,69,72,76,73}) << endl; // 1,1,4,2,1,1,0,0
    cout << tab({30,40,50,60}) << endl; // 1,1,1,0
    cout << tab({30,60,90}) << endl; // 1,1,0
    cout << endl;
    cout << tab2({73,74,75,71,69,72,76,73}) << endl; // 1,1,4,2,1,1,0,0
    cout << tab2({30,40,50,60}) << endl; // 1,1,1,0
    cout << tab2({30,60,90}) << endl; // 1,1,0
}
