#include "../../template.hpp"

int tab(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1));

    for (int k = 0; k <= K; ++k) {
        dp[k][1] = arr[0];
    }
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = max(dp[0][i - 1] + arr[i - 1], arr[i - 1]);
    }
    for (int k = 1; k <= K; ++k) {
        for (int i = 2; i <= n; ++i) {
            dp[k][i] = max({dp[k][i - 1] + arr[i - 1],
                            arr[i - 1],
                            dp[k - 1][i - 1]});
        }
    }
    int maxi = -INF;
    for (int i = 0; i <= n; ++i) {
        maxi = max(maxi, dp[K][i]);
    }
    return maxi;
}

deque<int> tab_elems(vi& arr, int K) {
    int n = arr.size();
    vvi dp(K + 1, vi(n + 1));
    vvvi prev(K + 1, vvi(n + 1));

    for (int k = 0; k <= K; ++k) {
        dp[k][1] = arr[0];
    }
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = max(dp[0][i - 1] + arr[i - 1], arr[i - 1]);
        if (dp[0][i] == dp[0][i - 1] + arr[i - 1]) {
            prev[0][i] = {0, i - 1, 1};
        }
        else {
            prev[0][i] = {0, i - 1, 2};
        }
    }
    for (int k = 1; k <= K; ++k) {
        for (int i = 2; i <= n; ++i) {
            dp[k][i] = max({dp[k][i - 1] + arr[i - 1],
                            arr[i - 1],
                            dp[k - 1][i - 1]});
            if (dp[k][i] == dp[k][i - 1] + arr[i - 1]) {
                prev[k][i] = {k, i - 1, 1};
            }
            else if (dp[k][i] == dp[k - 1][i - 1]) {
                prev[k][i] = {k - 1, i - 1, 0};
            }
            else if (dp[k][i] == arr[i - 1]) {
                prev[k][i] = {0, i - 1, 2};
            }
        }
    }
    int maxpos = 0, maxi = -INF;
    for (int i = 0; i <= n; ++i) {
        if (dp[K][i] > maxi) {
            maxi = dp[K][i];
            maxpos = i;
        }
    }
    deque<int> elems;
    for (vi at = prev[K][maxpos]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            elems.push_front(arr[at[1]]);
        }
        else if (at[2] == 2) {
            elems.push_front(arr[at[1]]);
            break;
        }
    }
    return elems;
}

int rec_straight(vi arr, int k, int n, int total) {
    if (n == 0) {
        return total;
    }
    if (k > 0) {
        return max({
                total,
                rec_straight(arr, k, n - 1, total + arr[n - 1]),
                rec_straight(arr, k - 1, n - 1, total),
                rec_straight(arr, k, n - 1, arr[n - 1])});
    }
    return max({
            total,
            rec_straight(arr, k, n - 1, total + arr[n - 1]),
            rec_straight(arr, k, n - 1, arr[n - 1])});
}

int rec_straight(vi arr, int k) {
    return rec_straight(arr, k, arr.size(), 0);
}

int tab_straight(vi arr, int K) {
    int n = arr.size();
    vvvi dp(n + 2, vvi(n + 2, vi(K + 1)));
    vector<vector<vector<unordered_set<int>>>> used(n + 2, vector<vector<unordered_set<int>>>(n + 2, vector<unordered_set<int>>(K + 1)));

    for (int i = 1; i <= n; ++i) {
        dp[i][i][0] = arr[i - 1];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][i + 1][0] = arr[i - 1] + arr[i];
    }

    for (int t = 2; t <= n; ++t) {
        for (int i = 1, j = i + t; j <= n; ++i, ++j) {
            dp[i][j][0] = arr[i - 1] + dp[i + 1][j][0];
        }
    }

    for (int k = 1; k <= K; ++k) {
        for (int t = 1; t <= n; ++t) {
            for (int i = 1, j = i + t; j <= n; ++i, ++j) {
                used[i][j][k] = used[i][j][k - 1];
                dp[i][j][k] = -INF;
                int elementIdx = -INF;
                for (int p = i; p <= j; ++p) {
                    if (used[i][j][k].count(p)) {
                        continue;
                    }
                    if (dp[i][j][k - 1] - arr[p - 1] > dp[i][j][k]) {
                        dp[i][j][k] = dp[i][j][k - 1] - arr[p - 1];
                        elementIdx = p;
                    }
                }
                if (elementIdx != -INF) {
                    used[i][j][k].insert(elementIdx);
                }
                else {
                    dp[i][j][k] = dp[i][j][k - 1];
                }
            }
        }
    }

    int ans = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i <= j and ans < dp[i][j][K]) {
                ans = max(ans, dp[i][j][K]);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 3, -4, 5};
    vi arr2 = {-2, 1, -3, 4, -1, -2, 1, 5, -3};

    cout << tab(arr1, 1) << '\n';
    cout << tab(arr2, 0) << '\n';
    cout << tab(arr2, 1) << '\n';
    cout << tab(arr2, 2) << '\n';
    cout << tab(arr2, 3) << '\n';
    cout << '\n';
    cout << tab_elems(arr1, 1) << '\n';
    cout << tab_elems(arr2, 0) << '\n';
    cout << tab_elems(arr2, 1) << '\n';
    cout << tab_elems(arr2, 2) << '\n';
    cout << tab_elems(arr2, 3) << '\n';
    cout << '\n';
    cout << rec_straight(arr1, 1) << '\n';
    cout << rec_straight(arr2, 0) << '\n';
    cout << rec_straight(arr2, 1) << '\n';
    cout << rec_straight(arr2, 2) << '\n';
    cout << rec_straight(arr2, 3) << '\n';
    cout << '\n';
    cout << tab_straight(arr1, 1) << '\n';
    cout << tab_straight(arr2, 0) << '\n';
    cout << tab_straight(arr2, 1) << '\n';
    cout << tab_straight(arr2, 2) << '\n';
    cout << tab_straight(arr2, 3) << '\n';
}
