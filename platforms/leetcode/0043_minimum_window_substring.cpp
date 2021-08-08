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

string tab2(const string& a, const string& b) {
    const int m = a.size();
    const int n = b.size();
    array<int, 64> pattern{};
    for (int i = 0; i < n; ++i) {
        ++pattern[b[i] - 'A'];
    }
    int pattern_size = 0;
    for (int i = 0; i < 64; ++i) {
        if (pattern[i] > 0) {
            ++pattern_size;
        }
    }
    array<int, 64> window{};
    int window_size = 0;
    int matched = 0;
    int ans = INF;
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        const char ch = a[i] - 'A';
        ++window[ch];
        ++window_size;
        if (window[ch] == pattern[ch]) {
            ++matched;
        }
        while (matched == pattern_size) {
            if (ans > window_size) {
                ans = window_size;
                idx = i - window_size + 1;
            }
            const char ch = a[i - window_size + 1] - 'A';
            --window[ch];
            --window_size;
            if (window[ch] < pattern[ch]) {
                --matched;
            }
        }
    }
    return ans == INF ? "" : a.substr(idx, ans);
}


int main() { TimeMeasure _; __x();
    cout << tab("ADOBECODEBANC", "ABC") << endl; // "BANC"
    cout << tab("a", "a") << endl; // a
    cout << tab("a", "aa") << endl; // ""
    cout << endl;
    cout << tab2("ADOBECODEBANC", "ABC") << endl; // "BANC"
    cout << tab2("a", "a") << endl; // a
    cout << tab2("a", "aa") << endl; // ""
}
