//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int Find(vector<int>& parent, vector<int>& rank, const int i) {
    const function<int(int)> FindRoot = [&](const int i){
        if (parent[i] == -1) return i;
        return parent[i] = FindRoot(parent[i]);
    };
    const int root = FindRoot(i);
    rank[root] = 1;
    return root;
}

void Union(vector<int>& parent, vector<int>& rank, int i, int j) {
    i = Find(parent, rank, i);
    j = Find(parent, rank, j);
    if (i == j) return;
    else if (rank[i] < rank[j]) parent[i] = j;
    else if (rank[i] > rank[j]) parent[j] = i;
    else parent[i] = j, rank[j] += 1;
}

void sol(istream& is) {
    int N, K, L; is >> N >> K >> L;
    vector<int> parent1(N, -1), rank1(N, 0);
    for (int i = 0; i < K; ++i) {
        int u, v; is >> u >> v; --u; --v;
        Union(parent1, rank1, u, v);
    }
    vector<int> parent2(N, -1), rank2(N, 0);
    for (int i = 0; i < L; ++i) {
        int u, v; is >> u >> v; --u; --v;
        Union(parent2, rank2, u, v);
    }
    map<pair<int, int>, int> connected;
    for (int i = 0; i < N; ++i) {
        ++connected[{Find(parent1, rank1, i), Find(parent2, rank2, i)}];
    }
    for (int i = 0; i < N; ++i) {
        cout << connected[{Find(parent1, rank1, i), Find(parent2, rank2, i)}] << ' ';
    }
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
4 3 1
1 2
2 3
3 4
2 3
)",
        R"(
4 2 2
1 2
2 3
1 4
2 3
)",
        R"(
7 4 4
1 2
2 3
2 5
6 7
3 5
4 5
3 4
6 7
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
    sol(std::cin);
}

#endif // LOCAL_MACHINE
