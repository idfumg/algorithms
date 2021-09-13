#include "../../template.hpp"

int sol(const vi& start, const vi& stop, const vi& profit) {
    const int n = start.size();
    vi idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&stop](const int i, const int j){
        return stop[i] < stop[j];
    });
    vi dp(n);
    dp[0] = profit[idxs[0]];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            const int idx = idxs[i];
            const int jdx = idxs[j];
            if (start[idx] >= stop[jdx]) {
                dp[i] = max(dp[i], dp[j] + profit[idx]);
            }
            else {
                dp[i] = max(dp[i], profit[idx]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int BinarySearch(const vi& start, const vi& stop, const vi& idxs, const int i) {
    int low = 0, high = i - 1;
    while (low <= high) {
        const int mid = low + (high - low) / 2;
        if (stop[idxs[mid]] <= start[idxs[i]]) {
            if (mid + 1 != i and stop[idxs[mid + 1]] <= start[idxs[i]]) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int sol2(const vi& start, const vi& stop, const vi& profit) {
    const int n = start.size();
    vi idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&stop](const int i, const int j){
        return stop[i] < stop[j];
    });
    vi dp(n);
    dp[0] = profit[idxs[0]];
    for (int i = 1; i < n; ++i) {
        const int idx = idxs[i];
        const int found = BinarySearch(start, stop, idxs, i);
        if (found != -1) {
            dp[i] = max(dp[i - 1], dp[found] + profit[idx]);
        }
        else {
            dp[i] = max(dp[i - 1], profit[idx]);
        }
    }
    return dp[n - 1];
}

int main() { TimeMeasure _; __x();
    cout << sol({1,2,3,3},{3,4,5,6},{50,10,40,70}) << endl; // 120
    cout << sol({1,2,3,4,6},{3,5,10,6,9},{20,20,100,70,60}) << endl; // 150
    cout << sol({1,1,1},{2,3,4},{5,6,4}) << endl; // 6
    cout << sol({4,2,4,8,2},{5,5,5,10,8},{1,2,8,10,4}) << endl; // 18
    cout << sol({43,13,36,31,40,5,47,13,28,16,2,11},{44,22,41,41,47,13,48,35,48,26,21,39},{8,20,3,19,16,8,11,13,2,15,1,1}) << endl; // 66
    cout << endl;
    cout << sol2({1,2,3,3},{3,4,5,6},{50,10,40,70}) << endl; // 120
    cout << sol2({1,2,3,4,6},{3,5,10,6,9},{20,20,100,70,60}) << endl; // 150
    cout << sol2({1,1,1},{2,3,4},{5,6,4}) << endl; // 6
    cout << sol2({4,2,4,8,2},{5,5,5,10,8},{1,2,8,10,4}) << endl; // 18
    cout << sol2({43,13,36,31,40,5,47,13,28,16,2,11},{44,22,41,41,47,13,48,35,48,26,21,39},{8,20,3,19,16,8,11,13,2,15,1,1}) << endl; // 66
}
