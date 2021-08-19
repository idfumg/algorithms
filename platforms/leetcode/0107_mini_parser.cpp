#include "../../template.hpp"

class NestedInteger {
private:
    vector<NestedInteger> arr;
    int value = -INF;

public:
    // Constructor initializes an empty nested list.
    NestedInteger() {}

    // Constructor initializes a single integer.
    NestedInteger(int value) : value(value) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {return value != -INF;}

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {return value;}

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {value = value;}

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {value = -INF; arr.push_back(ni);}

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {return arr;}
};

ostream& operator<<(ostream& os, const NestedInteger& param) {
    if (param.isInteger()) {
        os << param.getInteger();
    }
    else {
        os << '[';
        for (int i = 0; i < param.getList().size(); ++i) {
            os << param.getList()[i];
            if (i != param.getList().size() - 1) os << ',';
        }
        os << ']';
    }
    return os;
}

string read_number(const string& s, int& idx) {
    string temp;
    while (idx < s.size() and (isdigit(s[idx]) or s[idx] == '-')) {
        temp += s[idx++];
    }
    return temp;
}

NestedInteger rec(const string& s, int& idx) {
    if (s[idx] == '[' and s[idx + 1] == ']') {
        idx += 2;
        return NestedInteger();
    }
    else if (s[idx] == '[') {
        NestedInteger ans;
        ans.add(rec(s, ++idx));
        while (idx < s.size() and (s[idx] == ',')) ans.add(rec(s, ++idx));
        if (s[idx] == ']') ++idx;
        return ans;
    }
    else {
        const string temp = read_number(s, idx);
        return temp.empty() ? NestedInteger() : NestedInteger(stoi(temp));
    }
}

NestedInteger rec(const string& s) {
    int idx = 0;
    return rec(s, idx);
}

int main() { TimeMeasure _; __x();
    cout << rec("324") << endl; // 324
    cout << rec("[324]") << endl; // 324
    cout << rec("[324,123]") << endl; // [324,123]
    cout << rec("[324,-123]") << endl; // [324,-123]
    cout << rec("[324,[123,567]]") << endl; // [324,[123,567]]
    cout << rec("[123,[456,[789]]]") << endl; // [123,[456,[789]]]
    cout << rec("[123,456,[788,799,833],[[]],10,[]]") << endl; // [123,456,[788,799,833],[[]],10,[]]
}
