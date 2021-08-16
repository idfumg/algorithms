#include "../../template.hpp"

string tab(const string& s, const string& p) {
    string ans;
    for (const char ch : s) {
        ans += ch;
        if (ans.size() >= p.size()) {
            if (ans.substr(ans.size() - p.size() - 0, p.size()) == p) {
                for (int i = 0; i < p.size() and not ans.empty(); ++i) {
                    ans.pop_back();
                }
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("daabcbaabcbc", "abc") << endl; // dab
    cout << tab("axxxxyyyyb", "xy") << endl; // ab
}
