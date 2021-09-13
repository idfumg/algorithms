#include "../../template.hpp"

vector<vector<int>> graph;
vector<int> nums;
vector<int> ans;
vector<bool> visited;
vector<bool> has1;
int value;

void construct_graph(const vector<int>& parent) {
    for (int adj = 1; adj < static_cast<int>(parent.size()); ++adj) {
        graph[parent[adj]].push_back(adj);
    }
}

void dfs0(const int at) {
    has1[at] = nums[at] == 1;
    for (const int adj : graph[at]) {
        dfs0(adj);
        if (has1[adj]) has1[at] = 1;
    }
}

void dfs1(const int at) {
    visited[nums[at]] = true;
    for (const int adj : graph[at]) {
        dfs1(adj);
    }
}

void dfs(const int at) {
    if (not has1[at]) return;
    for (const int adj : graph[at]) if (has1[adj]) dfs(adj);
    for (const int adj : graph[at]) if (not has1[adj]) dfs1(adj);
    visited[nums[at]] = true;
    while (visited[value]) ++value;
    ans[at] = value;
}

vector<int> sol(const vector<int>& parent, const vector<int>& nums_) {
    const int maximum = *max_element(nums_.begin(), nums_.end()) + 2;

    graph = vector<vector<int>>(parent.size() + 1);
    nums = nums_;
    ans = vector<int>(nums.size(), 1);
    visited = vector<bool>(maximum);
    has1 = vector<bool>(maximum);
    value = 1;

    construct_graph(parent);
    dfs0(0);
    dfs(0);

    return ans;
}

const int fastio_ = ([](){ios_base::sync_with_stdio(0); cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({-1,0,1,0,3,3}, {5,4,6,2,1,3}) << endl; // [7,1,1,4,2,1]
    cout << sol({-1,0,0,0,2}, {6,4,3,2,1}) << endl; // [5,1,2,1,2]
    cout << sol({-1,2,3,0,2,4,1}, {2,3,4,5,6,7,8}) << endl; // [1,1,1,1,1,1,1]
    cout << sol({-1,0,0,2}, {1,2,3,4}) << endl; // [5,1,1,1]
}
