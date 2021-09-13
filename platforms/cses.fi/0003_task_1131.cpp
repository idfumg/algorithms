//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vi diameter;
vi height;

void dfs(vvi& graph, int at, int parent) {
    vi children_heights;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        dfs(graph, adj, at);
        children_heights.push_back(height[adj]);
    }

    sort(children_heights.begin(), children_heights.end());
    int n = children_heights.size();
    if (n == 0) diameter[at] = 0;
    else if (n == 1) diameter[at] = 1 + children_heights[0];
    else diameter[at] = 2 + children_heights[n - 1] + children_heights[n - 2];

    for (int adj : graph[at]) {
        if (adj == parent) continue;
        diameter[at] = max(diameter[at], diameter[adj]);
    }

    for (int adj : graph[at]) {
        if (adj == parent) continue;
        height[at] = max(height[at], 1 + height[adj]);
    }
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    int i = 0, j = 0;
    vvi graph(n + 1);
    while (is >> i >> j) {
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    diameter = vi(n + 1);
    height = vi(n + 1);
    dfs(graph, 1, 0);
    cout << diameter[1];
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
    sol(input1); // 3
    //sol(std::cin);
}
