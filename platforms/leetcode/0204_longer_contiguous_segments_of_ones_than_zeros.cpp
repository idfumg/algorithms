#include "../../template.hpp"

int sol(const string& s) {
    const int n = s.size();
    int ones = 0;
    int current_ones = 0;
    int zeroes = 0;
    int current_zeroes = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') ++current_ones;
        else current_ones = 0;

        if (s[i] == '0') ++current_zeroes;
        else current_zeroes = 0;

        ones = max(ones, current_ones);
        zeroes = max(zeroes, current_zeroes);
    }
    return ones > zeroes;
}

int main() { TimeMeasure _; //__x();
    cout << sol("1101") << endl; // 1
    cout << sol("111000") << endl; // 0
    cout << sol("110100010") << endl; // 0
}
