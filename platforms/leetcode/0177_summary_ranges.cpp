#include "../../template.hpp"

vector<string> sol(const vi& arr) {
    const int n = arr.size();

    vector<string> ans;

    if (n == 0) {
        return ans;
    }

    if (n == 1) {
        const string temp = to_string(arr[0]);
        ans.push_back(temp);
        return ans;
    }

    string temp = to_string(arr[0]);
    int count = 1;
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            if (count > 1) {
                temp += "->";
                temp += to_string(arr[i]);
            }
            ans.push_back(temp);
        }
        else if (arr[i + 1] != arr[i] + 1) {
            if (count > 1) {
                temp += "->";
                temp += to_string(arr[i]);
            }
            ans.push_back(temp);
            temp = to_string(arr[i + 1]);
            count = 0;
        }
        ++count;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({0,1,2,4,5,7}) << endl; // 0->2 4->5 7
    cout << sol({0,2,3,4,6,8,9}) << endl; // 0 2->4 6 8->9
    cout << sol({}) << endl; // []
    cout << sol({-1}) << endl; // [-1]
    cout << sol({0}) << endl; // [0]
    cout << sol({-2147483648,-2147483647,2147483647}) << endl; // [0]
}
