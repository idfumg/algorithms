#include "../../template.hpp"

vs sol(const vs& words1, const vs& words2) {
    array<int, 32> pattern{};
    for (const auto& word : words2) {
        array<int, 32> temp_pattern{};
        for (const char ch : word) {
            ++temp_pattern[ch - 'a'];
        }
        for (int i = 0; i < 32; ++i) {
            pattern[i] = max(pattern[i], temp_pattern[i]);
        }
    }
    vs ans;
    for (const auto& word : words1) {
        array<int, 32> current{};
        for (const char ch : word) {
            ++current[ch - 'a'];
        }
        bool is_valid = true;
        for (int i = 0; i < 32; ++i) {
            if (current[i] < pattern[i]) {
                is_valid = false;
            }
        }
        if (is_valid) {
            ans.push_back(word);
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({"amazon","apple","facebook","google","leetcode"}, {"e","o"}) << endl; // "facebook","google","leetcode"
    cout << sol({"amazon","apple","facebook","google","leetcode"}, {"l","e"}) << endl; // "apple","google","leetcode"
    cout << sol({"amazon","apple","facebook","google","leetcode"}, {"e","oo"}) << endl; // "facebook","google"
    cout << sol({"amazon","apple","facebook","google","leetcode"}, {"lo","eo"}) << endl; // "google","leetcode"
    cout << sol({"amazon","apple","facebook","google","leetcode"}, {"ec","oc","ceo"}) << endl; // "facebook","leetcode"
}
