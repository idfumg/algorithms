#include "../../template.hpp"

vi tab(const vi& arr, const int k) {
    const int n = arr.size();
    multiset<int> window;
    int window_size = 0;
    vi ans;
    for (int i = 0; i < n; ++i) {
        if (window_size < k) {
            window.insert(arr[i]);
            ++window_size;
        }
        if (window_size == k) {
            ans.push_back(*window.crbegin());
            window.erase(window.find(arr[i - window_size + 1]));
            --window_size;
        }
    }
    return ans;
}

vi tab2(const vi& arr, const int k) {
    const int n = arr.size();
    int window_size = 0;
    deque<vi> mq;
    vi ans(n - k + 1);
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (not mq.empty() and arr[i] >= arr[mq.back()[0]]) {
            count += mq.back()[1];
            mq.pop_back();
        }
        mq.push_back({i, count});
        if (++window_size == k) {
            ans[i - window_size + 1] = arr[mq.front()[0]];
            --window_size;
            if (--mq.front()[1] == 0) mq.pop_front();
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,3,-1,-3,5,3,6,7}, 3) << endl; // 3,3,5,5,6,7
    cout << tab({1}, 1) << endl; // 1
    cout << tab({1,-1}, 1) << endl; // 1,-1
    cout << tab({9,11}, 2) << endl; // 11
    cout << tab({4,-2}, 2) << endl; // 4
    cout << tab({1,3,1,2,0,5}, 3) << endl; // 3,3,2,5
    cout << tab({-7,-8,7,5,7,1,6,0}, 4) << endl; // 7,7,7,7,7
    cout << tab({9,10,9,-7,-4,-8,2,-6}, 5) << endl; // 10,10,9,2
    cout << tab({-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7}, 7) << endl; // 9,9,10,10,10,10,10,10,10,9,9,9,8,8
    cout << endl;
    cout << tab2({1,3,-1,-3,5,3,6,7}, 3) << endl; // 3,3,5,5,6,7
    cout << tab2({1}, 1) << endl; // 1
    cout << tab2({1,-1}, 1) << endl; // 1,-1
    cout << tab2({9,11}, 2) << endl; // 11
    cout << tab2({4,-2}, 2) << endl; // 4
    cout << tab2({1,3,1,2,0,5}, 3) << endl; // 3,3,2,5
    cout << tab2({-7,-8,7,5,7,1,6,0}, 4) << endl; // 7,7,7,7,7
    cout << tab2({9,10,9,-7,-4,-8,2,-6}, 5) << endl; // 10,10,9,2
    cout << tab2({-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7}, 7) << endl; // 9,9,10,10,10,10,10,10,10,9,9,9,8,8
}
