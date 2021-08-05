#include "../../template.hpp"

int rec(const vi& zeroes, const vi& ones, const int _0s, const int _1s, const int n, const int count) {
    if (_0s < 0 and _1s < 0) {
        return -INF;
    }
    if (n == 0) {
        return count;
    }
    if (zeroes[n - 1] <= _0s and ones[n - 1] <= _1s) {
        return max(rec(zeroes, ones, _0s, _1s, n - 1, count),
                   rec(zeroes, ones, _0s - zeroes[n - 1], _1s - ones[n - 1], n - 1, count + 1));
    }
    return rec(zeroes, ones, _0s, _1s, n - 1, count);
}

int rec(const vector<string>& arr, const int _0s, const int _1s) {
    const int n = arr.size();
    vi zeroes(n), ones(n);
    for (int i = 0; i < n; ++i) {
        for (const char ch : arr[i]) {
            if (ch == '0') ++zeroes[i];
            else ++ones[i];
        }
    }
    return rec(zeroes, ones, _0s, _1s, n, 0);
}

int rec2(const vi& zeroes, const vi& ones, const int _0s, const int _1s, const int n) {
    if (_0s < 0 and _1s < 0) {
        return -INF;
    }
    if (n == 0) {
        return 0;
    }
    if (zeroes[n - 1] <= _0s and ones[n - 1] <= _1s) {
        return max(rec2(zeroes, ones, _0s, _1s, n - 1),
                   rec2(zeroes, ones, _0s - zeroes[n - 1], _1s - ones[n - 1], n - 1) + 1);
    }
    return rec2(zeroes, ones, _0s, _1s, n - 1);
}

int rec2(const vector<string>& arr, const int _0s, const int _1s) {
    const int n = arr.size();
    vi zeroes(n), ones(n);
    for (int i = 0; i < n; ++i) {
        for (const char ch : arr[i]) {
            if (ch == '0') ++zeroes[i];
            else ++ones[i];
        }
    }
    return rec2(zeroes, ones, _0s, _1s, n);
}

int tab(const vector<string>& arr, const int _0s, const int _1s) {
    const int n = arr.size();
    vi zeroes(n), ones(n);
    for (int i = 0; i < n; ++i) {
        for (const char ch : arr[i]) {
            if (ch == '0') ++zeroes[i];
            else ++ones[i];
        }
    }
    vvvi dp(n + 1, vvi(_0s + 1, vi(_1s + 1, 0)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= _0s; ++j) {
            for (int k = 0; k <= _1s; ++k) {
                if (zeroes[i - 1] <= j and ones[i - 1] <= k) {
                    dp[i][j][k] = max(
                        dp[i - 1][j][k],
                        dp[i - 1][j - zeroes[i - 1]][k - ones[i - 1]] + 1);
                }
                else {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }
    return dp[n][_0s][_1s];
}

int tab2(const vector<string>& arr, const int _0s, const int _1s) {
    const int n = arr.size();
    vi zeroes(n), ones(n);
    for (int i = 0; i < n; ++i) {
        for (const char ch : arr[i]) {
            if (ch == '0') ++zeroes[i];
            else ++ones[i];
        }
    }
    vvvi dp(2, vvi(_0s + 1, vi(_1s + 1, 0)));
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        idx = i & 1;
        for (int j = 0; j <= _0s; ++j) {
            for (int k = 0; k <= _1s; ++k) {
                if (zeroes[i - 1] <= j and ones[i - 1] <= k) {
                    dp[idx][j][k] = max(
                        dp[1 - idx][j][k],
                        dp[1 - idx][j - zeroes[i - 1]][k - ones[i - 1]] + 1);
                }
                else {
                    dp[idx][j][k] = dp[1 - idx][j][k];
                }
            }
        }
    }
    return dp[idx][_0s][_1s];
}

int main() { TimeMeasure _; __x();
    cout << rec({"10","0001","111001","1","0"}, 5, 3) << endl; // 4
    cout << rec({"10","0","1"}, 1, 1) << endl; // 2
    //cout << rec({"11","11","0","0","10","1","1","0","11","1","0","111","11111000","0","11","000","1","1","0","00","1","101","001","000","0","00","0011","0","10000"}, 90, 66) << endl; // 29
    cout << endl;
    cout << rec2({"10","0001","111001","1","0"}, 5, 3) << endl; // 4
    cout << rec2({"10","0","1"}, 1, 1) << endl; // 2
    //cout << rec2({"11","11","0","0","10","1","1","0","11","1","0","111","11111000","0","11","000","1","1","0","00","1","101","001","000","0","00","0011","0","10000"}, 90, 66) << endl; // 29
    cout << endl;
    cout << tab({"10","0001","111001","1","0"}, 5, 3) << endl; // 4
    cout << tab({"10","0","1"}, 1, 1) << endl; // 2
    cout << tab({"11","11","0","0","10","1","1","0","11","1","0","111","11111000","0","11","000","1","1","0","00","1","101","001","000","0","00","0011","0","10000"}, 90, 66) << endl; // 29
    cout << endl;
    cout << tab2({"10","0001","111001","1","0"}, 5, 3) << endl; // 4
    cout << tab2({"10","0","1"}, 1, 1) << endl; // 2
    cout << tab2({"11","11","0","0","10","1","1","0","11","1","0","111","11111000","0","11","000","1","1","0","00","1","101","001","000","0","00","0011","0","10000"}, 90, 66) << endl; // 29
}
