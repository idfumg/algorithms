#include "../../template.hpp"

int tab(const string& s, const int k) {
    const int n = s.size();
    unordered_map<char, int> window;
    int window_size = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ++window[s[i]];
        ++window_size;
        int most_common = 0;
        for (const auto& [ch, count] : window) {
            most_common = max(most_common, count);
        }
        if (window_size - most_common <= k) {
            ans = max(ans, window_size);
        }
        else {
            --window[s[i - window_size + 1]];
            --window_size;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("ABAB", 2) << endl; // 4
    cout << tab("AABABBA", 1) << endl; // 4
}
