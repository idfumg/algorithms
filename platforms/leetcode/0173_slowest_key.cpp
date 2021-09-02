#include "../../template.hpp"

char sol(const vi& arr, const string& s) {
    const int n = arr.size();
    array<int, 32> keys{};
    keys[s[0] - 'a'] = arr[0];
    int maxi = arr[0];
    char ans = s[0];
    for (int i = 1; i < n; ++i) {
        keys[s[i] - 'a'] = max(keys[s[i] - 'a'], arr[i] - arr[i - 1]);
        if (maxi < keys[s[i] - 'a']) {
            maxi = keys[s[i] - 'a'];
            ans = s[i];
        }
        else if (maxi == keys[s[i] - 'a'] and s[i] > ans) {
            ans = s[i];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({9,29,49,50}, "cbcd") << endl; // c
    cout << sol({12,23,36,46,62}, "spuda") << endl; // a
    cout << sol({23,34,43,59,62,80,83,92,97}, "qgkzzihfc") << endl; // q
}
