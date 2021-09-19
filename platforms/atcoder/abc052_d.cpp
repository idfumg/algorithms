//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000000000 + 7;
#endif

void sol(istream& is) {
    int64_t n, m; is >> n >> m;

    vector<vector<int64_t>> graph(n, vector<int64_t>(n, INF));
    for (int i = 0; i < m; ++i) {
        int64_t a, b, c; is >> a >> b >> c; --a; --b;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }

    vector<vector<int64_t>> dp = graph;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][k] != INF and dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] != INF and dp[i][j] < graph[i][j]) {
                ++ans;
            }
        }
    }
    cout << ans;
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
3 3
1 2 1
1 3 1
2 3 3
)",
        R"(
3 2
1 2 1
2 3 1
)"
    };

    for (const auto& input : inputs) {
        istringstream is(input);
        sol(is);
        cout << endl;
    }
}

#else

int main() {
    const int fastio = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
    sol(std::cin);
}

#endif // LOCAL_MACHINE
