#include "../../template.hpp"

vector<i64> get_sieve(i64 n) {
    vector<i64> sieve(n + 1);
    for (i64 i = 0; i <= n; ++i) {
        sieve[i] = i;
    }
    for (i64 p = 2; p <= n; ++p) {
        if (sieve[p] == p) {
            for (i64 i = p * p; i <= n; i += p) {
                sieve[i] = p;
            }
        }
    }
    return sieve;
}

vector<i64> get_factors(vector<i64>& sieve, i64 n) {
    vector<i64> factors;
    for (i64 i = n; i > 1; i /= sieve[i]) {
        factors.push_back(sieve[i]);
    }
    return factors;
}

i64 Find(vector<i64>& parent, i64 i) {
    if (parent[i] == -1) return i;
    return parent[i] = Find(parent, parent[i]);
}

i64 Find(vector<i64>& parent, vector<i64>& rank, i64 i) {
    i64 root = Find(parent, i);
    rank[root] = 1;
    return root;
}

void Union(vector<i64>& parent, vector<i64>& rank, vector<i64>& count, i64 i, i64 j) {
    i = Find(parent, rank, i);
    j = Find(parent, rank, j);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        parent[i] = j;
        count[j] += count[i];
    }
    else if (rank[j] < rank[i]) {
        parent[j] = i;
        count[i] += count[j];
    }
    else {
        parent[i] = j;
        count[j] += count[i];
        rank[j] += 1;
    }
}

i32 sol(vector<i32> nums) {
    i64 maximum = *max_element(nums.begin(), nums.end());
    vector<i64> sieve = get_sieve(maximum + 1);
    vector<i64> parent(maximum + 1, -1), rank(maximum + 1, 0), count(maximum + 1, 1);
    for (i64 num : nums) {
        for (i64 factor : get_factors(sieve, num)) {
            Union(parent, rank, count, num, factor);
        }
    }
    unordered_map<i32, i32> groups;
    i32 ans = 0;
    for (i64 num : nums) {
        i64 root = Find(parent, rank, num);
        ans = max(ans, ++groups[root]);
    }
    return ans;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({4,6,15,35}) << endl; // 4
    cout << sol({20,50,9,63}) << endl; // 2
    cout << sol({2,3,6,7,4,12,21,39}) << endl; // 8
}
