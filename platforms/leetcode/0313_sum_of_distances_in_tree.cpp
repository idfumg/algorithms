#include "../../template.hpp"

vi sub_answers;
vi nodes_count;
vi answers;
vvi graph;

void get_sub_answers(int at, int parent) {
    int count = 1;
    int answer = 0;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        get_sub_answers(adj, at);
        count += nodes_count[adj];
        answer += sub_answers[adj] + nodes_count[adj];
    }
    nodes_count[at] = count;
    sub_answers[at] = answer;
}

void dfs(int at, int parent, int parent_partial) {
    answers[at] = sub_answers[at] + parent_partial + (graph.size() - nodes_count[at]);
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        int current_partial = answers[at] - (sub_answers[adj] + nodes_count[adj]);
        dfs(adj, at, current_partial);
    }
}

vi sol(int n, vvi edges) {
    graph = vvi(n);
    for (vi& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    sub_answers = vi(n);
    nodes_count = vi(n);
    answers = vi(n);
    get_sub_answers(0, -1);
    dfs(0, -1, 0);
    return answers;
}

int main() { TimeMeasure _; __x();
    cout << sol(6, {{0,1},{0,2},{2,3},{2,4},{2,5}}) << endl; // {8,12,6,10,10,10}
    cout << sol(1, {}) << endl; // {0}
    cout << sol(2, {{1,0}}) << endl; // {1,1}
}
