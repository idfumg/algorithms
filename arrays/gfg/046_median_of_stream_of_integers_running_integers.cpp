#include "../../template.hpp"

template<class LeftT, class RightT>
int avg(LeftT& left, RightT& right) {
    if (left.empty() and right.empty()) return 0;
    if (not left.empty() and right.empty()) return left.top();
    if (left.empty() and not right.empty()) return right.top();
    if (left.size() < right.size()) return right.top();
    if (left.size() > right.size()) return left.top();
    return (left.top() + right.top()) / 2;
}

template<class LeftT, class RightT>
int median(LeftT& left, RightT& right, int v) {
    if (left.empty() and right.empty()) {
        left.push(v);
    }
    else if (left.size() > right.size()) {
        if (left.top() < v) right.push(v);
        else right.push(left.top()), left.pop(), left.push(v);
    }
    else if (left.size() < right.size()) {
        if (right.top() > v) left.push(v);
        else left.push(right.top()), right.pop(), right.push(v);
    }
    else if (left.size() == right.size()) {
        if (left.top() > v and right.top() < v) right.push(left.top()), left.pop(), left.push(v);
        else if (left.top() > v and right.top() > v) left.push(v);
        else if (left.top() < v and right.top() < v) right.push(v);
        else if (left.top() < v and right.top() < v) left.push(v);
    }
    return avg(left, right);
}

void MediansOfTheStream(vi arr) {
    priority_queue<int> left;
    priority_queue<int, vi, greater<int>> right;
    for (int v : arr) {
        cout << median(left, right, v) << ' ';
    }
}

int main() { TimeMeasure _;
    MediansOfTheStream({5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}); // 5 10 5 4 3 4 5 6 7 6 7 6
}
