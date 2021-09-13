#include "../../template.hpp"

int sol(const vi& arr, const int i, const int j) {
    if (i >= j) return 0;
    int ans = INF;
    for (int k = i; k < j; ++k) {
        int left = *max_element(arr.begin() + i, arr.begin() + k + 1);
        int right = *max_element(arr.begin() + k + 1, arr.begin() + j + 1);
        ans = min(ans, sol(arr, i, k) + sol(arr, k + 1, j) + left * right);
    }
    return ans;
}

int sol(const vi& arr) {
    return sol(arr, 0, arr.size() - 1);
}

int tab(const vi& arr) {
    const int n = arr.size();
    vvi maxs(n + 2, vi(n + 1, -INF));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i <= j) maxs[i][j] = max(arr[i - 1], maxs[i + 1][j]);
        }
    }
    vvi dp(n + 2, vi(n + 1, INF));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= j) dp[i][j] = 0;
            else {
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxs[i][k] * maxs[k + 1][j]);
                }
            }
        }
    }
    return dp[1][n];
}

int tab2(const vi& arr) {
    deque<int> mq = {INF};
    int ans = 0;
    for (const int value : arr) {
        while (value >= mq.back()) {
            const int mid = mq.back(); mq.pop_back();
            ans += mid * min(mq.back(), value);
        }
        mq.push_back(value);
    }
    for (int i = 2; i < mq.size(); ++i) {
        ans += mq[i] * mq[i - 1];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({6,2,4}) << endl; // 32
    cout << sol({4,11}) << endl; // 44
    cout << sol({15,13,5,3,15}) << endl; // 500
    cout << endl;
    cout << tab({6,2,4}) << endl; // 32
    cout << tab({4,11}) << endl; // 44
    cout << tab({15,13,5,3,15}) << endl; // 500
    cout << endl;
    cout << tab2({6,2,4}) << endl; // 32
    cout << tab2({4,11}) << endl; // 44
    cout << tab2({15,13,5,3,15}) << endl; // 500
}
