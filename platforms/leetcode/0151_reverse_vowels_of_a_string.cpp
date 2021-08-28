#include "../../template.hpp"

bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string sol(const string& s) {
    string temp;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (is_vowel(s[i])) {
            temp.push_back(s[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    string ans;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (is_vowel(s[i])) ans += temp[idx++];
        else ans += s[i];
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("hello") << endl; // holle
    cout << sol("leetcode") << endl; // leotcede
    cout << sol("aA") << endl; // Aa
}
