#include "../../template.hpp"

string tab(const string& a, const string& b) {
    const int n = a.size();

    unordered_map<char, int> pattern;
    for (const char ch : b) {
        ++pattern[ch];
    }

    unordered_map<char, int> window;
    int window_min_size = INF;
    int window_min_idx = 0;
    int window_size = 0;
    int expected = pattern.size();
    int current = 0;
    for (int i = 0; i < n; ++i) {
        const char current_ch = a[i];
        ++window[current_ch];
        ++window_size;
        if (window[current_ch] == pattern[current_ch]) {
            ++current;
        }
        while (current == expected) {
            if (window_size < window_min_size) {
                window_min_size = window_size;
                window_min_idx = i - window_size + 1;
            }
            const char ch = a[i - window_size + 1];
            --window[ch];
            --window_size;
            if (window[ch] < pattern[ch]) {
                --current;
            }
        }
    }
    return window_min_size == INF ? "" : a.substr(window_min_idx, window_min_size);
}

int main() { TimeMeasure _; __x();
    cout << tab("ADOBECODEBANC", "ABC") << endl; // "BANC"
    cout << tab("a", "a") << endl; // a
    cout << tab("a", "aa") << endl; // ""
}
