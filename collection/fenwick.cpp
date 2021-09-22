#include <bits/stdc++.h>

using namespace std;

using i32 = std::int32_t;

class RangeSlow {
    vector<i32> arr;

public:
    template<class ... Args>
    explicit RangeSlow(Args&& ... args) : arr{forward<Args>(args)...} {}

    void update_at(i32 i, i32 value) {
        arr[i] += value;
    }

    void update_range(i32 i, i32 j, i32 value) {
        for (; i <= j; ++i) {
            arr[i] += value;
        }
    }

    i32 sum(i32 j) {
        i32 ans = 0;
        for (i32 i = 0; i <= j; ++i) {
            ans += arr[i];
        }
        return ans;
    }

    i32 sum(i32 i, i32 j) {
        i32 ans = 0;
        for (; i <= j; ++i) {
            ans += arr[i];
        }
        return ans;
    }
};

class FenwickTree {
    vector<i32> tree;

public:
    explicit FenwickTree(const vector<i32>& arr) {
        i32 n = arr.size();
        tree.resize(n + 2);
        for (i32 i = 1; i <= n; ++i) {
            tree[i] += arr[i - 1];
            if (i + (i & -i) <= n) tree[i + (i & -i)] += tree[i];
        }
    }

    explicit FenwickTree(i32 n) {
        tree.resize(n + 2);
    }

public:
    i32 query_prefix(i32 i) {
        i32 ans = 0;
        for (++i; i > 0; i -= (i & -i)) {
            ans += tree[i];
        }
        return ans;
    }

    i32 query(i32 i, i32 j) {
        return query_prefix(j) - query_prefix(i - 1);
    }

    void update_at(i32 i, i32 value) {
        for (++i; i < static_cast<i32>(tree.size()); i += i & -i) {
            tree[i] += value;
        }
    }

    void update_range(i32 i, i32 j, i32 value) {
        for (; i <= j; ++i) {
            update_at(i, value);
        }
    }

    void set(i32 i, i32 value) {
        ++i; update_at(i, value - query(i, i));
    }
};

template<class T>
T random_number(const T from, const T to) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<T> distribution{from, to};
    return distribution(generator);
}

template<class T>
std::vector<T> random_numbers(const std::size_t n, const T from, const T to) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<T> distribution{from, to};
    std::vector<T> numbers(n);
    for (std::size_t i = 0; i < n; ++i) {
        numbers[i] = distribution(generator);
    }
    return numbers;
}

int main() {
    const i32 TESTS = 100;
    const i32 QUERIES = 1000;
    const i32 SIZE = 3;
    const i32 FROM = 2;
    const i32 TO = 9;
    for (i32 i = 0; i < TESTS; ++i) {
        auto nums = random_numbers(SIZE, FROM, TO);

        RangeSlow rangeSlow(nums);
        FenwickTree fenwickTree(nums);

        for (i32 j = 0; j < QUERIES; ++j) {
            i32 rangeFrom = random_number(0, SIZE - 1);
            i32 rangeTo = random_number(rangeFrom, SIZE - 1);
            i32 value = random_number(FROM, TO);

            for (i32 k = rangeFrom; k <= rangeTo; ++k) nums[k] += value;
            rangeSlow.update_range(rangeFrom, rangeTo, value);
            fenwickTree.update_range(rangeFrom, rangeTo, value);

            // i32 idx = random_number(0, SIZE - 1);

            // nums[idx] += value;
            // rangeSlow.update_at(idx, value);
            // fenwickTree.update_at(idx, value);

            const i32 range_sum = rangeSlow.sum(rangeFrom, rangeTo);
            const i32 fenwick_tree_sum = fenwickTree.query(rangeFrom, rangeTo);
            if (range_sum != fenwick_tree_sum) {
                cout << "Wrong sum" << endl;
                for_each(nums.begin(), nums.end(), [](i32 n){cout << n << ' ';}); cout << endl;
                cout << rangeFrom << endl;
                cout << rangeTo << endl;
                cout << range_sum << endl;
                cout << fenwick_tree_sum << endl;
                return 0;
            }
        }
    }
    return 0;
}
