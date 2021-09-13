#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

void dfs(vvi& graph, vvi& dp, int at, int parent) {
    dp[at][0] = dp[at][1] = 0;

    bool is_leaf = true;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        is_leaf = false;
        dfs(graph, dp, adj, at);
    }
    if (is_leaf) return;

    vi prefix, suffix;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        prefix.push_back(max(dp[adj][1], dp[adj][0]));
        suffix.push_back(max(dp[adj][1], dp[adj][0]));
    }
    for (int i = 1; i < (int)prefix.size(); ++i) {
        prefix[i] += prefix[i - 1];
    }
    for (int i = (int)suffix.size() - 2; i >= 0; --i) {
        suffix[i] += suffix[i + 1];
    }

    dp[at][0] = suffix[0];
    int i = 0;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        int left = (i == 0) ? 0 : prefix[i - 1];
        int right = (i == (int)suffix.size() - 1) ? 0 : suffix[i + 1];
        dp[at][1] = max(dp[at][1], 1 + dp[adj][0] + left + right);
        ++i;
    }
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    int i = 0;
    int j = 0;
    vvi graph(n + 10);
    while (is >> i >> j) {
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    vvi dp(n + 10, vi(2));
    dfs(graph, dp, 1, 0);
    cout << max(dp[1][0], dp[1][1]);
}

void sol(const string& input) {
    istringstream is(input);
    sol(is);
    cout << endl;
}

int main() { //TimeMeasure _; __x();
    static const string input1 = R"(
5
1 2
1 3
3 4
3 5
)";
    static const string input2 = R"(
1
)";
    static const string input3 = R"(
10
7 5
5 3
7 4
1 9
9 2
10 1
8 1
8 6
4 8
)";
    static const string input4 = R"(
10
5 8
4 6
9 1
10 4
1 3
2 3
7 9
6 2
5 10
)";
    static const string input5 = R"(
10
6 3
2 8
10 8
4 10
7 3
8 7
1 5
5 9
10 9
)";

    // sol(input1); // 2
    // sol(input2); // 0
    // sol(input3); // 7
    // sol(input4); // 5
    // sol(input5); // 7
    sol(std::cin);
}
