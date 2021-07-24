#include "../../template.hpp"

string tab(const string& a, const string& b) {
    unordered_map<char, int> pattern;
    for (const char ch : b) {
        ++pattern[ch];
    }

    const int n = a.size();
    const int need = pattern.size();
    unordered_map<char, int> window;
    int current = 0;
    int window_size = 0;
    int window_min_size = INF;
    int position = 0;
    for (int i = 0; i < n; ++i) {
        ++window[a[i]];
        ++window_size;
        if (window[a[i]] == pattern[a[i]]) {
            ++current;
        }
        while (current == need) { // try to impair our window
            if (window_min_size > window_size) {
                window_min_size = window_size;
                position = i;
            }
            const char ch = a[i - window_size + 1];
            --window[ch];
            --window_size;
            if (window[ch] < pattern[ch]) {
                --current;
            }
        }
    }
    if (window_min_size == INF) return "";
    return a.substr(position - window_min_size + 1, window_min_size);
}

int main() { TimeMeasure _; __x();
    cout << tab("ADOBECODEBANC", "ABC") << endl; // "BANC"
    cout << tab("a", "a") << endl; // a
    cout << tab("a", "aa") << endl; // ""
}
