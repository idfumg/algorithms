#include "../../template.hpp"

string sol(const string& s, const string& t) {
    const int m = s.size();
    const int n = t.size();
    string ans(m + n, ' ');
    const int p = ans.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m and j < n) {
        if (i <= j) ans[k++] = s[i++];
        else ans[k++] = t[j++];
    }
    while (i < m) ans[k++] = s[i++];
    while (j < n) ans[k++] = t[j++];
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("abc", "pqr") << endl; // apbqcr
    cout << sol("ab", "pqrs") << endl; // apbqrs
    cout << sol("abcd", "pq") << endl; // apbqcd
}
