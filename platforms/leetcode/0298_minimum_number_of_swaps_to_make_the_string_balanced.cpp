#include "../../template.hpp"

int sol(string s) {
    const int n = s.size();
    int left = 0;
    int swaps = 0;
    int j = n - 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') ++left;
        else --left;

        if (left < 0) {
            while (j > i and s[j] != '[') --j;
            swap(s[i], s[j]);
            ++swaps;
            left = 1;
        }
    }
    return swaps;
}

int main() { TimeMeasure _; __x();
    cout << sol("][][") << endl; // 1
    cout << sol("]]][[[") << endl; // 2
    cout << sol("[]") << endl; // 0
}
