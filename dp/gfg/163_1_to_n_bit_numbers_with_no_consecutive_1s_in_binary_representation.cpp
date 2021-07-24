#include "../../template.hpp"

int with1(int n);

int with0(int n) {
    if (n == 1) return 1;
    return with0(n - 1) + with1(n - 1);
}

int with1(int n) {
    if (n == 1) return 1;
    return with0(n - 1);
}

int rec_count(int n) {
    return with0(n) + with1(n);
}

bool IsNonConsequentOnes(int n) {
    int prev = 0, digits = static_cast<int>(log2(n));
    for (int i = 1 << 0; i <= (1 << digits); prev = i, i <<= 1) {
        if ((n & prev) and (n & i)) {
            return false;
        }
    }
    return true;
}

vi naive(int n) {
    vi res;
    for (int i = 0; i < (1 << n); ++i) {
        if (IsNonConsequentOnes(i)) {
            res.push_back(i);
        }
    }
    return res;
}

void rec(int n, int prev, vi current) {
    if (n == 0) {
        int v = 0;
        for_each(current.rbegin(), current.rend(), [&](int i){v = v * 2 + i;});
        cout << v << ' ';
        return;
    }
    else if (prev == 0) {
        rec(n - 1, 0, current + 0);
        rec(n - 1, 1, current + 1);
    }
    else {
        rec(n - 1, 0, current + 0);
    }
}

void rec(int n) {
    vi current;
    rec(n - 1, 0, current + 0);
    rec(n - 1, 1, current + 1);
}

void rec2(int n, int prev, int current) {
    if (n == 0) {
        cout << current << ' ';
        return;
    }
    else if (prev == 0) {
        rec2(n - 1, 0, current * 2 + 0);
        rec2(n - 1, 1, current * 2 + 1);
    }
    else {
        rec2(n - 1, 0, current * 2 + 0);
    }
}

void rec2(int n) {
    rec2(n - 1, 0, 0);
    rec2(n - 1, 1, 1);
}

int main() { TimeMeasure _; __x();
    cout << rec_count(4) << endl; // 8
    cout << rec_count(3) << endl; // 5

    cout << naive(4) << endl; // 0 1 2 4 5 8 9 10
    cout << naive(3) << endl; // 0 1 2 4 5

    rec(4); cout << endl; // 0 1 2 4 5 8 9 10
    rec(3); cout << endl; // 0 1 2 4 5

    rec2(4); cout << endl; // 0 1 2 4 5 8 9 10
    rec2(3); cout << endl; // 0 1 2 4 5
}
