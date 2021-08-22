#include "../../template.hpp"

int tab(const vvi& arr) {
    const int n = arr.size();
    vi max_row(n);
    for (int i = 0; i < n; ++i) {
        max_row[i] = *max_element(arr[i].begin(), arr[i].end());
    }
    vi max_column(n);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            max_column[j] = max(max_column[j], arr[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += min(max_row[i], max_column[j]) - arr[i][j];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}}) << endl; // 35
}
