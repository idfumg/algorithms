#include "../../template.hpp"

int sol_(vi& arr) {
    int count = 1;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) {
            if (count < 2) {
                ++count;
            }
            else {
                int j = i + 1;
                for (; j < arr.size() and arr[j] == arr[i]; ++j) {
                    arr[j] = -INF;
                }
                arr[i] = -INF;
                count = 1;
                i = j - 1;
            }
        }
        else {
            count = 1;
        }
    }
    int i = 2;
    int j = 3;
    while (i < arr.size() and j < arr.size()) {
        if (arr[i] == -INF and arr[j] != -INF) {
            swap(arr[i], arr[j]);
            ++i;
            ++j;
        }
        else if (arr[i] == -INF and arr[j] == -INF) {
            ++j;
        }
        else {
            ++i;
            ++j;
        }
    }
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == -INF) {
            return i;
        }
    }
    return arr.size();
}

vi sol(vi arr) {
    const int k = sol_(arr);
    cout << k << ", ";
    return arr;
}

int main() { TimeMeasure _; //__x();
    cout << sol({1,1,1,2,2,3}) << endl; // 5, nums = [1,1,2,2,3,_]
    cout << sol({0,0,1,1,1,1,2,3,3}) << endl; // 7, nums = [0,0,1,1,2,3,3,_,_]
    cout << sol({1}) << endl; // 1, nums = [1]
}
