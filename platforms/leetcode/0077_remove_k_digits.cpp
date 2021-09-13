#include "../../template.hpp"

void rec(string s, int n, int k, string& elems, string& ans) {
    if (n < 0 and k != 0) return;
    if (n < 0 and k == 0) {
        if (not elems.empty()) {
            string temp = elems;
            while (temp.size() > 1 and temp.back() == '0') temp.pop_back();
            reverse(temp.begin(), temp.end());

            if (ans.size() < elems.size()) ans = temp;
            else if (ans.size() == elems.size() and ans > temp) ans = temp;
        }
        return;
    }

    rec(s, n - 1, k - 1, elems, ans);
    elems += s[n];
    rec(s, n - 1, k, elems, ans);
    elems.pop_back();
}

string rec(string s, int k) {
    string elems;
    string ans;
    rec(s, s.size() - 1, k, elems, ans);
    return ans.empty() ? "0" : ans;
}

int rec2(int num, int k) {
    if (k < 0) return INF;
    if (num == 0) return 0;
    return min(
        rec2(num / 10, k - 1),
        rec2(num / 10, k) * 10 + (num % 10));
}

string rec2(string s, int k) {
    int num = stoi(s);
    int ans = rec2(num, k);
    return to_string(ans);
}

string tab(string s, int k) {
    int n = s.size();

    deque<int> mq;
    for (int i = 0; i < n; ++i) {
        while (not mq.empty() and s[i] < s[mq.back()] and k-- > 0) {
            mq.pop_back();
        }
        mq.push_back(i);
    }

    while (k-- > 0 and not mq.empty()) mq.pop_back();
    while (not mq.empty() and s[mq.front()] == '0') mq.pop_front();

    string ans;
    for (int i : mq) {
        ans += s[i];
    }
    return ans.empty() ? "0" : ans;
}

int main() { TimeMeasure _; __x();
    cout << rec("1432219", 3) << endl; // 1219
    cout << rec("10200", 3) << endl; // 0
    cout << rec("10", 2) << endl; // 0
    cout << rec("9", 1) << endl; // 0
    cout << rec("91", 1) << endl; // 1
    cout << rec("19", 1) << endl; // 1
    cout << rec("10001", 4) << endl; // 0
    cout << endl;
    cout << rec2("1432219", 3) << endl; // 1219
    cout << rec2("10200", 3) << endl; // 0
    cout << rec2("10", 2) << endl; // 0
    cout << rec2("9", 1) << endl; // 0
    cout << rec2("91", 1) << endl; // 1
    cout << rec2("19", 1) << endl; // 1
    cout << rec2("10001", 4) << endl; // 0
    cout << endl;
    cout << tab("1432219", 3) << endl; // 1219
    cout << tab("10200", 3) << endl; // 0
    cout << tab("10", 2) << endl; // 0
    cout << tab("9", 1) << endl; // 0
    cout << tab("91", 1) << endl; // 1
    cout << tab("19", 1) << endl; // 1
    cout << tab("10001", 4) << endl; // 0
}
