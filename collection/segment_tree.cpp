#include <bits/stdc++.h>
//#include "../template.hpp"

using namespace std;

using i32 = std::int32_t;
const int INF = 1e9 + 7;

class RangeSlow {
public:
    vector<i32> arr;

public:
    template<class ... Args>
    RangeSlow(Args&& ... args) : arr{forward<Args>(args)...} {
    }

    void update_range(i32 i, i32 j, i32 value) {
        for (i32 k = i; k <= j; ++k) {
            arr[k] += value;
        }
    }

    void update_at(i32 i, i32 value) {
        arr[i] += value;
    }

    i32 minimum(i32 i, i32 j) {
        i32 ans = arr[i];
        for (i32 k = i + 1; k <= j; ++k) {
            ans = min(ans, arr[k]);
        }
        return ans;
    }

    i32 maximum(i32 i, i32 j) {
        i32 ans = arr[i];
        for (i32 k = i + 1; k <= j; ++k) {
            ans = max(ans, arr[k]);
        }
        return ans;
    }

    i32 sum(i32 i, i32 j) {
        i32 ans = 0;
        for (i32 k = i; k <= j; ++k) {
            ans += arr[k];
        }
        return ans;
    }

    i32 gcd(i32 i, i32 j) {
        i32 ans = arr[i];
        for (i32 k = i + 1; k <= j; ++k) {
            ans = std::gcd(ans, arr[k]);
        }
        return ans;
    }
};

template<class T>
class SegmentTree {
protected:
    vector<i32> lo;
    vector<i32> hi;
    vector<i32> lazy;
    vector<i32> tree;

public:
    static unique_ptr<SegmentTree> create(const vector<i32>& arr) {
        auto segmentTree = make_unique<T>();
        i32 size = 3 * arr.size() + 1;
        segmentTree->lo.resize(size);
        segmentTree->hi.resize(size);
        segmentTree->lazy.resize(size);
        segmentTree->tree.resize(size);
        segmentTree->init(arr, 1, 0, arr.size() - 1);
        return segmentTree;
    }

public:
    void update_range(i32 i, i32 j, i32 value) { update_range(1, i, j, value); }
    void update_at(i32 i, i32 value) { update_at(1, i, value); }
    i32 query(i32 i, i32 j) { return query(1, i, j); }

public:
    virtual ~SegmentTree() = default;

protected:
    virtual i32 default_value() const = 0;
    virtual i32 combine(i32 a, i32 b) const = 0;
    virtual void propogate(i32 node, i32 value) = 0;

private:
    void propogate_lazy(i32 node, i32 value) {
        propogate(node, value);
        if (lo[node] != hi[node]) {
            lazy[2 * node] += value;
            lazy[2 * node + 1] += value;
        }
        lazy[node] = 0;
    }

    void init(const vector<i32>& arr, i32 node, i32 i, i32 j) {
        lo[node] = i;
        hi[node] = j;

        if (i == j) { tree[node] = arr[i]; return; }

        i32 mid = i + (j - i) / 2;
        init(arr, 2 * node, i, mid);
        init(arr, 2 * node + 1, mid + 1, j);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update_range(i32 node, i32 i, i32 j, i32 value) {
        if (lazy[node] != 0) propogate_lazy(node, lazy[node]);
        if (j < lo[node] or hi[node] < i) return;
        if (i <= lo[node] and hi[node] <= j) { propogate_lazy(node, value); return; }

        update_range(2 * node, i, j, value);
        update_range(2 * node + 1, i, j, value);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update_at(i32 node, i32 i, i32 value) {
        if (lazy[node] != 0) propogate_lazy(node, lazy[node]);
        if (i < lo[node] or i > hi[node]) return;
        if (lo[node] == i and hi[node] == i) { propogate_lazy(node, value); return; }

        update_at(2 * node, i, value);
        update_at(2 * node + 1, i, value);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    i32 query(i32 node, i32 i, i32 j) {
        if (lazy[node] != 0) propogate_lazy(node, lazy[node]);
        if (j < lo[node] or hi[node] < i) return default_value();
        if (i <= lo[node] and hi[node] <= j) return tree[node];
        return combine(query(2 * node, i, j),
                       query(2 * node + 1, i, j));
    }
};

class SegmentTreeMin : public SegmentTree<SegmentTreeMin> {
public:
    i32 default_value() const override { return INF; }
    i32 combine(i32 a, i32 b) const override { return min(a, b); }
    void propogate(i32 node, i32 value) override { tree[node] += value; }
};

class SegmentTreeMax : public SegmentTree<SegmentTreeMax> {
public:
    i32 default_value() const override { return -INF; }
    i32 combine(i32 a, i32 b) const override { return max(a, b); }
    void propogate(i32 node, i32 value) override { tree[node] += value; }
};

class SegmentTreeSum : public SegmentTree<SegmentTreeSum> {
public:
    i32 default_value() const override { return 0; }
    i32 combine(i32 a, i32 b) const override { return a + b; }
    void propogate(i32 node, i32 value) override { tree[node] += (hi[node] - lo[node] + 1) * value; }
};

class SegmentTreeGcd : public SegmentTree<SegmentTreeGcd> {
public:
    i32 default_value() const override { return 0; }
    i32 combine(i32 a, i32 b) const override { return gcd(a, b); }
    void propogate(i32 node, i32 value) override { tree[node] += value; }
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
    const i32 SIZE = 5;
    const i32 FROM = 2;
    const i32 TO = 9;
    for (i32 i = 0; i < TESTS; ++i) {
        auto nums = random_numbers(SIZE, FROM, TO);

        RangeSlow rangeSlow(nums);
        const auto segmentTreeMin = SegmentTreeMin::create(nums);
        const auto segmentTreeMax = SegmentTreeMax::create(nums);
        const auto segmentTreeSum = SegmentTreeSum::create(nums);

        for (i32 j = 0; j < QUERIES; ++j) {
            i32 rangeFrom = random_number(0, SIZE - 1);
            i32 rangeTo = random_number(rangeFrom, SIZE - 1);
            i32 value = random_number(FROM, TO);

            for (i32 k = rangeFrom; k <= rangeTo; ++k) nums[k] += value;
            rangeSlow.update_range(rangeFrom, rangeTo, value);
            segmentTreeMin->update_range(rangeFrom, rangeTo, value);
            segmentTreeMax->update_range(rangeFrom, rangeTo, value);
            segmentTreeSum->update_range(rangeFrom, rangeTo, value);

            i32 idx = random_number(0, SIZE - 1);

            nums[idx] += value;
            rangeSlow.update_at(idx, value);
            segmentTreeMin->update_at(idx, value);
            segmentTreeMax->update_at(idx, value);
            segmentTreeSum->update_at(idx, value);

            const i32 range_min = rangeSlow.minimum(rangeFrom, rangeTo);
            const i32 segment_tree_min = segmentTreeMin->query(rangeFrom, rangeTo);
            if (range_min != segment_tree_min) {
                cout << "Wrong minimum" << endl;
                cout << rangeFrom << endl;
                cout << rangeTo << endl;
                cout << range_min << endl;
                cout << segment_tree_min << endl;
                return 0;
            }

            const i32 range_max = rangeSlow.maximum(rangeFrom, rangeTo);
            const i32 segment_tree_max = segmentTreeMax->query(rangeFrom, rangeTo);
            if (range_max != segment_tree_max) {
                cout << "Wrong maximum" << endl;
                cout << rangeFrom << endl;
                cout << rangeTo << endl;
                cout << range_max << endl;
                cout << segment_tree_max << endl;
                return 0;
            }

            const i32 range_sum = rangeSlow.sum(rangeFrom, rangeTo);
            const i32 segment_tree_sum = segmentTreeSum->query(rangeFrom, rangeTo);
            if (range_sum != segment_tree_sum) {
                cout << "Wrong sum" << endl;
                cout << rangeFrom << endl;
                cout << rangeTo << endl;
                cout << range_sum << endl;
                cout << segment_tree_sum << endl;
                return 0;
            }
        }
    }
}
