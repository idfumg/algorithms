#include "../../template.hpp"

vi tab(const string& s) {
    const int n = s.size();
    array<int, 27> prev{};
    for (int i = 0; i < 27; ++i) {
        prev[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (prev[s[i] - 'a'] == -1) {
            prev[s[i] - 'a'] = i;
        }
    }
    vi ans;
    int lastidx = INF;
    int count = 0;
    for (int i = n - 1; i >= 0; --i) {
        ++count;
        if (prev[s[i] - 'a'] < lastidx) {
            lastidx = prev[s[i] - 'a'];
        }
        if (i == lastidx and count > 0) {
            ans.push_back(count);
            count = 0;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("ababcbacadefegdehijhklij") << endl; // 9,7,8
    cout << tab("eccbbbbdec") << endl; // 10
    cout << tab("caedbdedda") << endl; // 1,9
    cout << tab("eaaaabaaec") << endl; // 9,1
}
