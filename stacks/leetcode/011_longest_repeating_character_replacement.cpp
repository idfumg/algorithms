#include "../../template.hpp"

int tab(const string& s, const int k) {
    int n = s.size();
    int ans = 0;
    unordered_map<char, int> matched;
    for (int i = 0; i < n; ++i) {
        ++matched[s[i]];
        int total_count = 0;
        for (const auto& [ch, count] : matched) {
            total_count += count;
        }
        int most_common_count = 0;
        for (const auto& [ch, count] : matched) {
            most_common_count = max(most_common_count, count);
        }
        int to_convert = total_count - most_common_count;
        if (to_convert <= k) {
            ans = max(ans, total_count);
        }
        else {
            --matched[s[i - total_count + 1]];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("ABAB", 2) << endl; // 4
    cout << tab("AABABBA", 1) << endl; // 4
}
