#include "../template.hpp"

struct TreeNode final {
    int id;
    vector<TreeNode*> kids;
    explicit TreeNode(const int id) noexcept : id(id), kids() {}
};

static void AddEdge(vvi& graph, const int from, const int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

static TreeNode* MakeTree(const vvi& graph, TreeNode* root, const TreeNode* parent){
    for (const auto& adj : graph[root->id]) {
        if (parent and parent->id == adj) continue;
        const auto kid = new TreeNode(adj);
        root->kids.push_back(MakeTree(graph, kid, root));
    }
    return root;
}

static TreeNode* RootTree(const vvi& graph, const int from) {
    const auto root = new TreeNode(from);
    return MakeTree(graph, root, nullptr);
}

static string EncodeTree(const TreeNode* root) {
    if (not root) return "";
    vector<string> encodings;
    for (const auto& kid : root->kids) {
        encodings.push_back(EncodeTree(kid));
    }
    sort(encodings.begin(), encodings.end());
    string ans;
    for (const auto& encoding : encodings) {
        ans += encoding;
    }
    return "(" + ans + ")";
}

static vi FindTreeCenters(const vvi& graph) {
    const int n = graph.size();
    vi degree(n);
    deque<int> q;
    for (int at = 0; at < n; ++at) {
        degree[at] = graph[at].size();
        if (degree[at] == 1) {
            q.push_back(at);
        }
    }
    int total = q.size();
    while (not q.empty() and total < n) {
        for (int m = q.size(); m > 0; --m) {
            const int at = q.front(); q.pop_front();
            for (const int adj : graph[at]) {
                if (--degree[adj] == 1) {
                    q.push_back(adj);
                }
            }
        }
        total += q.size();
    }
    return vi(q.begin(), q.end());
}

static bool TreesAreIsomorphic(const vvi& graph1, const vvi& graph2) {
    const auto centers1 = FindTreeCenters(graph1);
    const auto centers2 = FindTreeCenters(graph2);
    const auto root1 = RootTree(graph1, centers1[0]);
    const auto encoding1 = EncodeTree(root1);
    for (const auto& center : centers2) {
        const auto root2 = RootTree(graph2, center);
        const auto encoding2 = EncodeTree(root2);
        if (encoding1 == encoding2) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    vvi tree1(5);
    AddEdge(tree1, 2, 0);
    AddEdge(tree1, 3, 4);
    AddEdge(tree1, 2, 1);
    AddEdge(tree1, 2, 3);

    vvi tree2(5);
    AddEdge(tree2, 1, 0);
    AddEdge(tree2, 2, 4);
    AddEdge(tree2, 1, 3);
    AddEdge(tree2, 1, 2);

    if (not TreesAreIsomorphic(tree1, tree2)) {
        cout << "Oops, these tree should be isomorphic!" << endl;
    }

    vvi tree3(10);
    AddEdge(tree3, 0, 2);
    AddEdge(tree3, 0, 1);
    AddEdge(tree3, 0, 3);
    AddEdge(tree3, 2, 6);
    AddEdge(tree3, 2, 7);
    AddEdge(tree3, 1, 4);
    AddEdge(tree3, 1, 5);
    AddEdge(tree3, 5, 9);
    AddEdge(tree3, 3, 8);

    const auto root3 = RootTree(tree3, 0);

    if (EncodeTree(root3) != "(((())())(()())(()))") {
        cout << ("Tree encoding is wrong: " + EncodeTree(root3)) << endl;
    }
}
