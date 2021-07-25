#include "../../template.hpp"

int tab(const vi& arr, const int target) { // O(n^2)
    int n = arr.size();

    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    int ans = INF;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (prefix[j + 1] - prefix[i] >= target) {
                ans = min(ans, j - i + 1);
            }
        }
    }

    return ans == INF ? -1 : ans;
}

int tab2(const vi& arr, const int target) { // O(n)
    int n = arr.size();

    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    int ans = INF;

    deque<int> starts;
    for (int i = 1; i <= n; ++i) {
        if (prefix[i] >= target) {
            ans = min(ans, i);
        }

        while (not starts.empty() and prefix[i] - prefix[starts.front()]>=target){
            ans = min(ans, i - starts.front());
            starts.pop_front();
        }

        while (not starts.empty() and prefix[i] <= prefix[starts.back()]) {
            starts.pop_back();
        }

        starts.push_back(i);
    }

    return ans == INF ? -1 : ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({84,-37,32,40,95}, 167) << endl; // 3
    cout << tab({2,-1,2}, 3) << endl; // 3
    cout << tab({1,2}, 4) << endl; // -1
    cout << tab({1}, 1) << endl; // 1
    cout << endl;
    cout << tab2({84,-37,32,40,95}, 167) << endl; // 3
    cout << tab2({2,-1,2}, 3) << endl; // 3
    cout << tab2({1,2}, 4) << endl; // -1
    cout << tab2({1}, 1) << endl; // 1
}
