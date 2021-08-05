#include "../../template.hpp"

int tab(const string& s, const vi& cost) {
    const int n = s.size();
    int ans = 0;
    for (int i = n; i >= 2; --i) {
        if (s[i - 1] == s[i - 2]) {
            int maxi = -INF;
            int total = 0;
            while (i >= 2 and s[i - 1] == s[i - 2]) {
                maxi = max(maxi, cost[i - 1]);
                total += cost[i - 1];
                --i;
            }
            maxi = max(maxi, cost[i - 1]);
            total += cost[i - 1];
            if (maxi != -INF) ans += total - maxi;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("abaac", {1,2,3,4,5}) << endl; // 3
    cout << tab("abc", {1,2,3}) << endl; // 0
    cout << tab("aabaa", {1,2,3,4,1}) << endl; // 2
    cout << tab("aaabbbabbbb", {3,5,10,7,5,3,5,5,4,8,1}) << endl; // 26
}
