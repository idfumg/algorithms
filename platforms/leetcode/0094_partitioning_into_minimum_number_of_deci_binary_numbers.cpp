#include "../../template.hpp"

int tab(string s) {
    sort(s.begin(), s.end());
    const int n = s.size();
    int k = 0;
    int ans = 0;
    for (const char ch : s) {
        const int count = ch - '0' - k;
        ans += count;
        k += count;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("32") << endl; // 3
    cout << tab("82734") << endl; // 8
    cout << tab("27346209830709182346") << endl; // 9
}
