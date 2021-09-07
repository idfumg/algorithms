#include "../../template.hpp"

string sol(const string& s) {
    string alphas, digits;
    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i])) alphas.push_back(s[i]);
        else digits.push_back(s[i]);
    }

    const int m = alphas.size();
    const int n = digits.size();
    const int p = m + n;
    if (m == 0 and n == 1) return digits;
    if (n == 0 and m == 1) return alphas;
    if (m == 0 or n == 0) return "";

    string temp(m + n, ' ');
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m and j < n and k < p) {
        if (k & 1) temp[k++] = m > n ? digits[j++] : alphas[i++];
        else temp[k++] = m > n ? alphas[i++] : digits[j++];
    }

    if (k > 0 and k < p and isalpha(temp[k - 1]) and j >= 0 and j < n) temp[k++] = digits[j++];
    else if (k > 0 and k < p and isdigit(temp[k - 1]) and i >= 0 and i < m) temp[k++] = alphas[i++];

    if (i != m and j != n) return "";
    return temp;
}

int main() { TimeMeasure _; //__x();
    cout << sol("a0b1c2") << endl; // 0a1b2c
    cout << sol("leetcode") << endl; // ""
    cout << sol("1229857369") << endl; // ""
    cout << sol("covid2019") << endl; // c2o0v1i9d
    cout << sol("ab123") << endl; // 1a2b3
    cout << sol("k") << endl; // k
}
