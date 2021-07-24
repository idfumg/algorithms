#include "../../template.hpp"

vi tab(const vi& arr, const uint64_t k) {
    const int n = arr.size();
    deque<vector<uint64_t>> mq; // 0 - index, 1 - count in monoqueue
    for (uint64_t i = 0; i < k; ++i) {
        uint64_t count = 1;
        while (not mq.empty() and arr[i] > arr[mq.back()[0]]) {
            count += mq.back()[1];
            mq.pop_back();
        }
        mq.push_back({i, count});
    }
    vi ans = {arr[mq.front()[0]]};
    for (uint64_t i = k; i < n; ++i) {
        if (mq.front()[1] == 1) mq.pop_front();
        else --mq.front()[1];
        uint64_t count = 1;
        while (not mq.empty() and arr[i] > arr[mq.back()[0]]) {
            count += mq.back()[1];
            mq.pop_back();
        }
        mq.push_back({i, count});
        ans.push_back(arr[mq.front()[0]]);
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
}
