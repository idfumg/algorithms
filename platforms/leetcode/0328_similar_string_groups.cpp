#include "../../template.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;
//const i32 INF = 1000000000 + 7;
const i32 fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();

i32 find(array<i32, 301>& parent, i32 i) {
    if (parent[i] == -1) return i;
    return parent[i] = find(parent, parent[i]);
}

void join(array<i32, 301>& parent, i32 i, i32 j) {
    i = find(parent, i);
    j = find(parent, j);
    if (i == j) return;
    parent[i] = j;
}

array<array<i32, 26>, 301> get_words_counts(vector<string>& words) {
    i32 n = words.size();
    array<array<i32, 26>, 301> ans{};
    for (i32 i = 0; i < n; ++i) {
        for (char ch : words[i]) {
            ++ans[i][ch - 'a'];
        }
    }
    return ans;
}

bool are_similar(const string& s, const string& t, array<i32, 26>& sm, array<i32, 26>& tm) {
    i32 n = s.size(), count = 0;
    for (i32 i = 0; i < n; ++i) {
        count += s[i] != t[i];
    }
    return (count == 2 or count == 0) and sm == tm;
}

i32 sol(vector<string> words) {
    i32 n = words.size();
    array<array<i32, 26>, 301> counts = get_words_counts(words);
    array<i32, 301> parent{};
    parent.fill(-1);
    for (i32 i = 0; i < n; ++i) {
        for (i32 j = i + 1; j < n; ++j) {
            i32 root1 = find(parent, i);
            i32 root2 = find(parent, j);
            if (root1 != root2 and are_similar(words[i], words[j], counts[i], counts[j])) {
                join(parent, i, j);
            }
        }
    }
    return count(parent.begin(), parent.begin() + n, -1);
}

int main() { TimeMeasure _;
    cout << sol({"tars","rats","arts","star"}) << endl; // 2
    cout << sol({"omv","ovm"}) << endl; // 1
    cout << sol({"ajdidocuyh","djdyaohuic","ddjyhuicoa","djdhaoyuic","ddjoiuycha","ddhoiuycja","ajdydocuih","ddjiouycha","ajdydohuic","ddjyouicha"}) << endl; // 2
    cout << sol({"abc", "abc"}) << endl; // 1
}
