#include "../../template.hpp"

string sol(const string& s) {
    const int n = s.size();
    deque<string> mq;
    deque<string> temp;
    for (const char ch : s) {
        if (ch == '(') {
            mq.push_back("(");
        }
        else if (ch == ')') {
            while (not mq.empty() and mq.back() != "(") {
                temp.push_front(mq.back());
                mq.pop_back();
            }
            if (not mq.empty() and mq.back() == "(") {
                temp.push_back(")");
                temp.push_front("(");
                mq.pop_back();
            }
            string t;
            for (int i = 0; i < temp.size(); ++i) {
                t += move(temp[i]);
            }
            temp.clear();
            mq.push_back(move(t));
        }
        else {
            mq.push_back(string(1, ch));
        }
    }
    string ans;
    for (int i = 0; i < mq.size(); ++i) {
        if (mq[i] != "(") ans += mq[i];
    }
    mq.clear();
    return ans;
}

string sol2(const string& s) {
    const int n = s.size();
    vb is_good(n);
    deque<int> mq;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            mq.push_back(i);
        }
        else if (s[i] == ')') {
            if (not mq.empty()) {
                is_good[i] = true;
                is_good[mq.back()] = true;
                mq.pop_back();
            }
        }
        else {
            is_good[i] = true;
        }
    }
    string ans;
    ans.reserve(s.size());
    for (int i = 0; i < n; ++i) {
        if (is_good[i]) {
            ans += s[i];
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("lee(t(c)o)de)") << endl; // "lee(t(c)o)de"
    cout << sol("a)b(c)d") << endl; // "ab(c)d"
    cout << sol("))((") << endl; // ""
    cout << sol("(a(b(c)d)") << endl; // "a(b(c)d)"
    cout << sol("())()(((") << endl; // "()()"
    cout << endl;
    cout << sol2("lee(t(c)o)de)") << endl; // "lee(t(c)o)de"
    cout << sol2("a)b(c)d") << endl; // "ab(c)d"
    cout << sol2("))((") << endl; // ""
    cout << sol2("(a(b(c)d)") << endl; // "a(b(c)d)"
    cout << sol2("())()(((") << endl; // "()()"
}
