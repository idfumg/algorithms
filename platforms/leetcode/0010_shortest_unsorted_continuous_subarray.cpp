#include "../../template.hpp"

int tab(const vi& arr) {
    const int n = arr.size();

    deque<int> mq;
    vi left(n);
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and arr[i] < arr[mq.back()]) mq.pop_back();
        if (mq.empty()) left[i] = -1;
        else left[i] = mq.back();
        mq.push_back(i);
    }

    mq.clear();
    vi right(n);
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and arr[i] > arr[mq.back()]) mq.pop_back();
        if (mq.empty()) right[i] = n;
        else right[i] = mq.back();
        mq.push_back(i);
    }

    int low = -1;
    for (int i = 0; i < n; ++i) {
        if (left[i] != i - 1 or right[i] != i + 1) {
            low = i;
            break;
        }
    }

    int high = n;
    for (int i = n - 1; i >= 0; --i) {
        if (left[i] != i - 1 or right[i] != i + 1) {
            high = i;
            break;
        }
    }

    if (low >= high or (low == -1 and high == n)) {
        return 0;
    }

    int mini = INF;
    int maxi = -INF;
    for (int i = low; i <= high; ++i) {
        if (arr[i] < mini) mini = arr[i];
        if (arr[i] > maxi) maxi = arr[i];
    }

    while (low > 0 and arr[low - 1] > mini) --low;
    while (high < n - 1 and arr[high + 1] < maxi) ++high;

    return high - low + 1;
}

int tab2(const vi& arr) {
    const int n = arr.size();

    int i = 0;
    while (i < n - 1 and arr[i] <= arr[i + 1]) ++i;

    if (i == n - 1) return 0;

    int j = n - 1;
    while (j > 0 and arr[j] >= arr[j - 1]) --j;

    int mini = INF;
    int maxi = -INF;
    for (int k = i; k <= j; ++k) {
        mini = min(mini, arr[k]);
        maxi = max(maxi, arr[k]);
    }

    while (i > 0 and arr[i - 1] > mini) --i;
    while (j < n - 1 and arr[j + 1] < maxi) ++j;

    return j - i + 1;
}

int tab2_opt(const vi& arr) {
    const int n = arr.size();
    int left = -1;
    int right = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (left == -1 and arr[i] > arr[i + 1]) left = i;
        if (right == -1 and n - i - 2 >= 0 and arr[n - i - 1] < arr[n - i - 2]) right = n - i - 1;
    }

    if (left == -1) return 0;

    int mini = INF;
    int maxi = -INF;
    for (int k = left; k <= right; ++k) {
        mini = min(mini, arr[k]);
        maxi = max(maxi, arr[k]);
    }

    while (left > 0 and arr[left - 1] > mini) --left;
    while (right < n - 1 and arr[right + 1] < maxi) ++right;

    return right - left + 1;
}

int main() { TimeMeasure _; __x();
    cout << tab({2,6,4,8,10,9,15}) << endl; // 5
    cout << tab({1,2,3,4}) << endl; // 0
    cout << tab({4,3,2,1}) << endl; // 4
    cout << tab({1}) << endl; // 0
    cout << tab({1,3,2,2,2}) << endl; // 4
    cout << tab({2,3,3,2,4}) << endl; // 3
    cout << tab({1,1}) << endl; // 0
    cout << tab({1,2,4,5,3}) << endl; // 3
    cout << tab({1,3,2,4,5}) << endl; // 2
    cout << endl;
    cout << tab2({2,6,4,8,10,9,15}) << endl; // 5
    cout << tab2({1,2,3,4}) << endl; // 0
    cout << tab2({4,3,2,1}) << endl; // 4
    cout << tab2({1}) << endl; // 0
    cout << tab2({1,3,2,2,2}) << endl; // 4
    cout << tab2({2,3,3,2,4}) << endl; // 3
    cout << tab2({1,1}) << endl; // 0
    cout << tab2({1,2,4,5,3}) << endl; // 3
    cout << tab2({1,3,2,4,5}) << endl; // 2
    cout << endl;
    cout << tab2_opt({2,6,4,8,10,9,15}) << endl; // 5
    cout << tab2_opt({1,2,3,4}) << endl; // 0
    cout << tab2_opt({4,3,2,1}) << endl; // 4
    cout << tab2_opt({1}) << endl; // 0
    cout << tab2_opt({1,3,2,2,2}) << endl; // 4
    cout << tab2_opt({2,3,3,2,4}) << endl; // 3
    cout << tab2_opt({1,1}) << endl; // 0
    cout << tab2_opt({1,2,4,5,3}) << endl; // 3
    cout << tab2_opt({1,3,2,4,5}) << endl; // 2
}
