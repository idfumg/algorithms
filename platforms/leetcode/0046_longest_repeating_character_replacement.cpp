#include "../../template.hpp"

int tab(const string& s, const int k) {
    const int n = s.size();
    unordered_map<int, int> window;
    int window_size = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ++window[s[i]];
        ++window_size;
        int same = 0;
        for (const auto& [ch, count] : window) {
            same = max(same, count);
        }
        if (window_size - same <= k) {
            ans = max(ans, window_size);
        }
        else {
            --window[s[i - window_size + 1]];
            --window_size;
        }
    }
    return ans;
}

int tab_opt(const string& s, const int k) {
    const int n = s.size();
    std::array<int, 32> window{};
    int window_size = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ++window[s[i] - 'A'];
        ++window_size;
        if (window_size - *max_element(window.cbegin(), window.cend()) <= k) {
            ans = max(ans, window_size);
        }
        else {
            --window[s[i - window_size + 1] - 'A'];
            --window_size;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("ABAB", 2) << endl; // 4
    cout << tab("AABABBA", 1) << endl; // 4
    cout << tab("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4) << endl; // 7
    cout << endl;
    cout << tab_opt("ABAB", 2) << endl; // 4
    cout << tab_opt("AABABBA", 1) << endl; // 4
    cout << tab_opt("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4) << endl; // 7
}
