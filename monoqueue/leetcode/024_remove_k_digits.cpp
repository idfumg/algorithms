#include "../../template.hpp"

int rec(const int n, const int k) {
    if (n < 0) return INF;
    if (n == 0) return 0;
    if (k > 0) return min(rec(n / 10, k) * 10 + (n % 10), rec(n / 10, k - 1));
    return rec(n / 10, 0) * 10 + n % 10;
}

string rec(const string& s, const int k) {
    const int ans = rec(stoi(s), k);
    return to_string(ans);
}

string tab(const string& s, const int K) {
    if (s.empty()) return "";
    const int n = stoi(s);
    vvi dp(n + 1, vi(K + 1));
    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k <= K; ++k) {
            if (i == 0) dp[i][k] = 0;
            else if (k > 0) dp[i][k] = min(dp[i / 10][k] * 10 + (i % 10), dp[i / 10][k - 1]);
            else dp[i][k] = dp[i / 10][0] * 10 + (i % 10);
        }
    }
    return to_string(dp[n][K]);
}

string tab2(const string& s, int k) {
    const int n = s.size();
    deque<int> mq;
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and s[i] < s[mq.back()] and k > 0) {
            mq.pop_back();
            --k;
        }
        mq.push_back(i);
    }
    while (mq.size() > 1 and s[mq.front()] == '0') {
        mq.pop_front();
    }
    while (not mq.empty() and k > 0) {
        mq.pop_back();
        --k;
    }
    string ans;
    for (int i = 0; i < mq.size(); ++i) {
        ans.push_back(s[mq[i]]);
    }
    return ans.empty() ? "0" : ans;
}

int main() { TimeMeasure _; __x();
    cout << rec("1432219", 3) << endl; // 1219
    cout << rec("10200", 3) << endl; // 0
    cout << rec("10", 2) << endl; // 0
    cout << rec("9", 1) << endl; // 0
    cout << rec("91", 1) << endl; // 1
    cout << rec("19", 1) << endl; // 9
    cout << endl;
    cout << tab("1432219", 3) << endl; // 1219
    cout << tab("10200", 3) << endl; // 0
    cout << tab("10", 2) << endl; // 0
    cout << tab("9", 1) << endl; // 0
    cout << tab("91", 1) << endl; // 1
    cout << tab("19", 1) << endl; // 9
    cout << endl;
    cout << tab2("1432219", 3) << endl; // 1219
    cout << tab2("10200", 3) << endl; // 0
    cout << tab2("10", 2) << endl; // 0
    cout << tab2("9", 1) << endl; // 0
    cout << tab2("91", 1) << endl; // 1
    cout << tab2("19", 1) << endl; // 9
}
