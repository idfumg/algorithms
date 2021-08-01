#include "../../template.hpp"

vi NewArr(const vi& arr, const int k) {
    vi res;
    const int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (i != k - 1) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

int rec_straight(const vi& arr, const int n, map<vi, int>& tab) {
    if (arr.size() == 0 or n == 0) return 0;
    if (tab.count(arr)) return tab[arr];

    const int a = n == 1 ? 1 : arr[n - 2];
    const int b = n == arr.size() ? 1 : arr[n];
    const int cost = a * arr[n - 1] * b;
    const vi newarr = NewArr(arr, n);

    return tab[arr] = max(
        rec_straight(arr, n - 1, tab),
        rec_straight(newarr, newarr.size(), tab) + cost);
}

int rec_straight(const vi& arr) {
    map<vi, int> tab;
    return rec_straight(arr, arr.size(), tab);
}

int rec(const vi& arr, const int i, const int j, vvi& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -INF) return dp[i][j];
    int ans = -INF;
    for (int p = i; p <= j; ++p) {
        const int left = rec(arr, i, p - 1, dp);
        const int right = rec(arr, p + 1, j, dp);
        const int cost = arr[i - 1] * arr[p] * arr[j + 1];
        ans = max(ans, left + right + cost);
    }
    return dp[i][j] = ans;
}

int rec(vi arr) {
    arr.insert(arr.begin(), 1);
    arr.push_back(1);
    vvi dp(arr.size(), vi(arr.size(), -INF));
    return rec(arr, 1, arr.size() - 2, dp);
}

int tab(vi arr) {
    arr.insert(arr.begin(), 1);
    arr.push_back(1);
    const int n = arr.size();
    vvi dp(n + 1, vi(n + 1));
    for (int k = 0; k < n - 1; ++k) {
        for (int i = 1, j = i + k; j < n - 1; ++i, ++j) {
            int ans = -INF;
            for (int p = i; p <= j; ++p) {
                const int left = dp[i][p - 1];
                const int right = dp[p + 1][j];
                const int cost = arr[i - 1] * arr[p] * arr[j + 1];
                ans = max(ans, left + cost + right);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n - 2];
}

int main() { TimeMeasure _; __x();
    cout << rec_straight({3,1,5,8}) << endl; // 167
    cout << rec_straight({1,5}) << endl; // 10
    cout << rec_straight({35,16,83,87,84,59,48,41,20}) << endl; // 1611332
    cout << rec_straight({35,16,83,87,84,59,48,41,20,54}) << endl; // 1849648
    cout << rec_straight({8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2}) << endl; // 3414
    cout << endl;
    cout << rec({3,1,5,8}) << endl;
    cout << rec({1,5}) << endl;
    cout << rec({35,16,83,87,84,59,48,41,20}) << endl;
    cout << rec({35,16,83,87,84,59,48,41,20,54}) << endl;
    cout << rec({8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2}) << endl;
    cout << endl;
    cout << tab({3,1,5,8}) << endl;
    cout << tab({1,5}) << endl;
    cout << tab({35,16,83,87,84,59,48,41,20}) << endl;
    cout << tab({35,16,83,87,84,59,48,41,20,54}) << endl;
    cout << tab({8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2}) << endl;
}
