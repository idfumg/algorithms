#include "../../template.hpp"

int sol(vi values, int target, int i, int j) {
    if (target < 0) return INF;
    if (target == 0) return 0;
    if (i > j) return INF;
    return 1 + min(sol(values, target - values[i], i + 1, j), sol(values, target - values[j], i, j - 1));
}

int sol(vi values, int target) {
    int ans = min(INF, sol(values, target, 0, values.size() - 1));
    return ans == INF ? -1 : ans;
}

int sol2(vi values, int target) {
    target = reduce(values.begin(), values.end()) - target;
    int window = 0;
    int window_size = 0;
    int n = values.size();
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        window += values[i];
        ++window_size;
        while (window_size > 0 and window > target) {
            window -= values[i - window_size + 1];
            --window_size;
        }
        if (window == target) {
            ans = min(ans, n - window_size);
        }
    }
    return ans == INF ? -1 : ans;
}

int sol3(vi values, int target) {
    unordered_map<int, int> sums = {{0, -1}};
    int n = values.size();
    int sum = 0;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        sum += values[i];
        sums.insert({sum, i});
        if (sum == target) {
            ans = min(ans, i + 1);
        }
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += values[i];
        if (sums.count(target - sum) and sums[target - sum] < i) {
            ans = min(ans, n - i + sums[target - sum] + 1);
        }
    }
    return ans == INF ? -1 : ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({1,1,4,2,3}, 5) << endl; // 2
    cout << sol({5,6,7,8,9}, 4) << endl; // -1
    cout << sol({3,2,20,1,1,3}, 10) << endl; // 5
    cout << sol({1,1}, 3) << endl; // -1
    cout << sol({8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309}, 134365) << endl; // 16
    cout << sol({5,2,3,1,1}, 5) << endl; // 1
    cout << endl;
    cout << sol2({1,1,4,2,3}, 5) << endl; // 2
    cout << sol2({5,6,7,8,9}, 4) << endl; // -1
    cout << sol2({3,2,20,1,1,3}, 10) << endl; // 5
    cout << sol2({1,1}, 3) << endl; // -1
    cout << sol2({8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309}, 134365) << endl; // 16
    cout << sol2({5,2,3,1,1}, 5) << endl; // 1
    cout << endl;
    cout << sol3({1,1,4,2,3}, 5) << endl; // 2
    cout << sol3({5,6,7,8,9}, 4) << endl; // -1
    cout << sol3({3,2,20,1,1,3}, 10) << endl; // 5
    cout << sol3({1,1}, 3) << endl; // -1
    cout << sol3({8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309}, 134365) << endl; // 16
    cout << sol3({5,2,3,1,1}, 5) << endl; // 1
}
