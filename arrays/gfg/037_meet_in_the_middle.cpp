#include "../../template.hpp"

vi genSubsets(vi arr, int from, int count, int target) {
    vi ans;
    for (int i = 0; i < (1 << count); ++i) {
        int sum = 0;
        for (int j = 0; j < count; ++j) {
            if (i & (1 << j)) {
                sum += arr[from + j];
            }
        }
        if (target >= sum) {
            ans.push_back(sum);
        }
    }
    return ans;
}

int LowerBound(vi arr, int key) {
    int n = arr.size(), low = 0, high = n - 1;
    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key) low = mid + 1;
        else high = mid;
    }
    return low;
}

int MaxSumSubsetLessThanS(vi arr, int target) {
    int n = arr.size();

    vi left = genSubsets(arr, 0, n / 2, target);
    vi right = genSubsets(arr, n / 2, n - n / 2, target);
    sort(right.begin(), right.end());

    int ans = 0;
    for (int v : left) {
        int diff = target - v;
        int idx = LowerBound(right, diff);

        if (right[idx] == diff) {
            return target;
        }
        else if (right[idx] < diff) {
            ans = max(ans, right[idx] + v);
        }
        else if (right[idx] > diff and idx > 0) {
            ans = max(ans, right[idx - 1] + v);
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << MaxSumSubsetLessThanS({45, 34, 4, 12, 5, 2}, 42) << '\n'; // 41
    cout << MaxSumSubsetLessThanS({3, 34, 4, 12, 5, 2}, 10) << '\n'; // 10
}
