#include "../../template.hpp"

vector<string> sol(const vector<string>& words1, const vector<string>& words2) {
    vector<string> ans;
    array<int, 32> pattern{};
    for (const auto& word : words2) {
        array<int, 32> temp{};
        for (const char ch : word) {
            ++temp[ch - 'a'];
        }
        for (int i = 0; i < 32; ++i) {
            pattern[i] = max(pattern[i], temp[i]);
        }
    }
    int required = 0;
    for (int i = 0; i < 32; ++i) {
        if (pattern[i] > 0) {
            ++required;
        }
    }
    for (const string& word : words1) {
        array<int, 32> temp{};
        for (const char ch : word) {
            ++temp[ch - 'a'];
        }
        int current = 0;
        for (int i = 0; i < 32; ++i) {
            if (temp[i] >= pattern[i] and pattern[i] > 0) {
                ++current;
            }
        }
        if (current == required) {
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
