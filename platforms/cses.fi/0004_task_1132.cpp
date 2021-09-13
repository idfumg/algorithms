//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000000000 + 7;
using vi = vector<int>;
using vvi = vector<vi>;

vi height;
vi distances;

void generate_heights(vvi& graph, int at, int parent) {
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        generate_heights(graph, adj, at);
        height[at] = max(height[at], 1 + height[adj]);
    }
}

void dfs(vvi& graph, int at, int parent, int parent_distance) {
    vi prefix_max, suffix_max;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        prefix_max.push_back(height[adj]);
        suffix_max.push_back(height[adj]);
    }

    int n = prefix_max.size();
    for (int i = 1; i < n; ++i) {
        prefix_max[i] = max(prefix_max[i - 1], prefix_max[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suffix_max[i] = max(suffix_max[i + 1], suffix_max[i]);
    }

    int i = 0;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        int left = (i == 0) ? -INF : prefix_max[i - 1];
        int right = (i == n - 1) ? -INF : suffix_max[i + 1];
        int current_distance = 1 + max(parent_distance, max(left, right));
        dfs(graph, adj, at, current_distance);
        ++i;
    }
    distances[at] = 1 + max(parent_distance, prefix_max.empty() ? -1 : prefix_max[n - 1]);
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    int i = 0, j = 0;
    vvi graph(n + 1);
    while (is >> i >> j) {
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    height = vi(n + 1);
    distances = vi(n + 1);
    generate_heights(graph, 1, 0);
    dfs(graph, 1, 0, -1);
    for (int i = 1; i <= n; ++i) {
        cout << distances[i] << ' ';
    }
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
    sol(input1); // 2 3 2 3 3
    //sol(std::cin);
}
