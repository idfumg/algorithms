//#include "../../template.hpp"
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000000000 + 7;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

vll sub_answers;
vll nodes_count;
vll answers;

void get_sub_answers(vvi& graph, int at, int parent) {
    ll count = 1;
    ll answer = 0;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        get_sub_answers(graph, adj, at);
        count += nodes_count[adj];
        answer += sub_answers[adj] + nodes_count[adj];
    }
    nodes_count[at] = count;
    sub_answers[at] = answer;
}

void dfs(vvi& graph, int at, int parent, ll parent_partial) {
    answers[at] = sub_answers[at] + parent_partial + (graph.size() - 1 - nodes_count[at]);
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        ll current_partial = answers[at] - (sub_answers[adj] + nodes_count[adj]);
        dfs(graph, adj, at, current_partial);
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
    sub_answers = vll(n + 1);
    nodes_count = vll(n + 1);
    answers = vll(n + 1);
    get_sub_answers(graph, 1, 0);
    dfs(graph, 1, 0, 0);
    for (int i = 1; i < (int)answers.size(); ++i) {
        cout << answers[i] << ' ';
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
    sol(input1); // 6 9 5 8 8
    //sol(std::cin);
}
