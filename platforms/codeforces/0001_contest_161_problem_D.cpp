//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
//constexpr int INF = 1000000000 + 7;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

vvi graph;
vvi distances;
vvi answers;

void generate_distances_dfs(int at, int parent, int K) {
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        generate_distances_dfs(adj, at, K);
    }
    distances[at][0] = 1;
    for (int k = 1; k <= K; ++k) {
        for (int adj : graph[at]) {
            if (adj == parent) continue;
            distances[at][k] += distances[adj][k - 1];
        }
    }
}

void dfs(int at, int parent, int K) {
    answers[at] = distances[at];
    if (parent != 0) {
        answers[at][1] += distances[parent][0];
        for (int k = 2; k <= K; ++k) {
            answers[at][k] = distances[at][k] + (answers[parent][k - 1] - distances[at][k - 2]);
        }
    }
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        dfs(adj, at, K);
    }
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    int k = 0; is >> k;
    int i = 0, j = 0;
    graph = vvi(n + 1);
    while (is >> i >> j) {
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    distances = vvi(n + 1, vi(k + 1));
    answers = vvi(n + 1, vi(k + 1));
    generate_distances_dfs(1, 0, k);
    dfs(1, 0, k);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += answers[i][k];
    }
    cout << ans / 2;
}

void sol(const string& input) {
    istringstream is(input);
    sol(is);
    cout << endl;
}

int main() { //TimeMeasure _; __x();
    static const string input1 = R"(
5 2
1 2
2 3
3 4
2 5
)";
    static const string input2 = R"(
5 3
1 2
2 3
3 4
4 5
)";
    sol(input1); // 4
    sol(input2); // 2
    //sol(std::cin);
}
