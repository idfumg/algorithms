//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vi dp;

void dfs(vvi& graph, int at, int parent) {
    int count = 0;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        dfs(graph, adj, at);
        count += 1 + dp[adj];
    }
    dp[at] = count;
}

void sol(istream& is = std::cin) {
    int n = 0; is >> n;
    vvi graph(n);
    for (int i = 1; i < n; ++i) {
        int j = 0; is >> j;
        graph[i].push_back(j - 1);
        graph[j - 1].push_back(i);
    }
    dp.clear();
    dp.resize(n);
    dfs(graph, 0, -1);
    for (int value : dp) cout << value << ' ';
}

void sol(const string& input) {
    istringstream is(input);
    sol(is);
    cout << endl;
}

int main() { //TimeMeasure _; __x();
    static const string input1 = R"(
5
1 1 2 3
)";
    static const string input2 = R"(
10
1 2 2 3 1 5 3 7 9
)";

    sol(input1); // 4 1 1 0 0
    sol(input2); // 9 7 5 0 3 0 2 0 1 0
    //sol(std::cin);
}
