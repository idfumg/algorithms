#include "../../template.hpp"

using i64 = int64_t;

vector<i64> get_sieve(i64 n) {
    vector<i64> sieve(n + 1, 0);
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

void Union(vector<i64>& parent, i64 i, i64 j) {
    i = Find(parent, i);
    j = Find(parent, j);
    if (i == j) return;
    parent[i] = j;
}

i64 sol(vector<i64> nums) {
    i64 maximum = *max_element(nums.begin(), nums.end());
    vector<i64> parent(maximum + 1, -1);
    vector<i64> sieve = get_sieve(maximum + 1);

    for (i64 num : nums) {
        for (i64 factor : get_factors(sieve, num)) {
            Union(parent, num, factor);
        }
    }

    vector<i64> sorted = nums;
    sort(sorted.begin(), sorted.end());

    i64 n = nums.size();
    for (i64 i = 0; i < n; ++i) {
        i64 root1 = Find(parent, nums[i]);
        i64 root2 = Find(parent, sorted[i]);
        if (root1 != root2) {
            return 0;
        }
    }

    return 1;
}

const int fastio_ = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
int main() { TimeMeasure _;
    cout << sol({7,21,3}) << endl; // 1
    cout << sol({5,2,6,2}) << endl; // 0
    cout << sol({10,5,9,3,15}) << endl; // 1
}
