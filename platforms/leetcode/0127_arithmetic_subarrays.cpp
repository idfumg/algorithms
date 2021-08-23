#include "../../template.hpp"

vb tab(const vi& arr, const vi& l, const vi& r) {
    vb ans(l.size(), true);
    for (int i = 0; i < l.size(); ++i) {
        vi temp(arr.begin() + l[i], arr.begin() + r[i] + 1);
        sort(temp.begin(), temp.end());
        const int d = temp[1] - temp[0];
        for (int j = 1; j < temp.size(); ++j) {
            if (temp[j] - temp[j - 1] != d) {
                ans[i] = false;
                break;
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({4,6,5,9,3,7}, {0,0,2}, {2,3,5}) << endl; // true,false,true
    cout << tab({-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10}, {0,1,6,4,8,7}, {4,4,9,7,9,10}) << endl; // false,true,false,false,true,true
}
