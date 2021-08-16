#include "../../template.hpp"

vi tab(const string& s) {
    const int n = s.size();
    vi count1(n);
    vi dp1(n);
    for (int i = 1; i < n; ++i) {
        dp1[i] = dp1[i - 1] + count1[i - 1];
        count1[i] = count1[i - 1];
        if (s[i - 1] == '1') {
            ++dp1[i];
            ++count1[i];
        }
    }
    vi count2(n);
    vi dp2(n);
    vi ans(n);
    ans[n - 1] = dp1[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        dp2[i] = dp2[i + 1] + count2[i + 1];
        count2[i] = count2[i + 1];
        if (s[i + 1] == '1') {
            ++dp2[i];
            ++count2[i];
        }

        ans[i] = dp1[i] + dp2[i];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("110") << endl; // 1,1,3
    cout << tab("001011") << endl; // 11,8,5,4,3,4
}
