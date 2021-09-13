#include "../../template.hpp"

int sol(vi values, int L, int R) {
    int n = values.size();
    deque<int> mq;
    vi left(n, -1);
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and values[i] > values[mq.back()]) mq.pop_back();
        if (not mq.empty()) left[i] = mq.back();
        mq.push_back(i);
    }
    mq.clear();
    vi right(n, n);
    for (int i = n - 1; i >= 0; --i) {
        while (not mq.empty() and values[i] >= values[mq.back()]) mq.pop_back();
        if (not mq.empty()) right[i] = mq.back();
        mq.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] >= L and values[i] <= R) {
            ans += (i - left[i]) * (right[i] - i);
        }
    }
    return ans;
}

int sol2(vi values, int L, int R) {
    int ans = 0;
    int top = 0;
    int bottom = 0;
    for (int value : values) {
        if (value > R) top = 0;
        else ans += ++top;
        if (value >= L) bottom = 0;
        else ans -= ++bottom;
    }
    return ans;
}

int sol3(vi elems, int L, int R) {
    int n = elems.size();
    int ans = 0;
    int i = 0;
    int window = 0;
    for (int j = 0; j < n; ++j) {
        if (elems[j] >= L and elems[j] <= R) {
            window = j - i + 1;
            ans += window;
        }
        else if (elems[j] < L) {
            ans += window;
        }
        else {
            i = j + 1;
            window = 0;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({2,1,4,3}, 2, 3) << endl; // 3
    cout << sol({2,9,2,5,6}, 2, 8) << endl; // 7
    cout << sol({73,55,36,5,55,14,9,7,72,52}, 32, 69) << endl; // 22
    cout << endl;
    cout << sol2({2,1,4,3}, 2, 3) << endl; // 3
    cout << sol2({2,9,2,5,6}, 2, 8) << endl; // 7
    cout << sol2({73,55,36,5,55,14,9,7,72,52}, 32, 69) << endl; // 22
    cout << endl;
    cout << sol3({2,1,4,3}, 2, 3) << endl; // 3
    cout << sol3({2,9,2,5,6}, 2, 8) << endl; // 7
    cout << sol3({73,55,36,5,55,14,9,7,72,52}, 32, 69) << endl; // 22
}
