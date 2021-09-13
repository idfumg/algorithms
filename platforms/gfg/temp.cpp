#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std::literals::string_literals;
using namespace std;

template<class T, class U>
static ostream& operator << (ostream& os, const map<T, U>& tab) noexcept {
    os << '\n';
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os;// << endl;
}

bool delim(const char c) {
    return c == ' ';
}

bool is_op(const char c) {
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '>';
}

bool is_var(const char c) {
    return c == '_';
}

int priority(const char op) {
    if (op == '+' or op == '-') return 1;
    if (op == '*' or op == '/') return 2;
    if (op == '>') return 3;
    return -1;
}

void process_op(stack<int>& st, const char op) {
    const int r = st.top(); st.pop();
    const int l = st.top(); st.pop();
    switch (op) {
    case '+': st.push(l + r); return;
    case '-': st.push(l - r); return;
    case '*': st.push(l * r); return;
    case '/': st.push(l / r); return;
    case '>': st.push(l > r); return;
    }
    throw std::runtime_error("Error: wrong value of operand: "s + op);
}

int read_number(const string& s, int& i) {
    int number = 0;
    for (; i < s.size() and isalnum(s[i]); ++i) {
        number = number * 10 + s[i] - '0';
    }
    --i;
    return number;
}

int read_var(const string& s, int& i, unordered_map<string, int>& vars) {
    string var = {s[i++]};
    for (; i < s.size() and isalnum(s[i]); ++i) {
        var += s[i];
    }
    --i;
    return vars.at(var);
}

string pre_handle_dice(const string& s, unordered_map<string, int>& vars, vector<int>& arr) {
    int k = 1;
    string ans;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'd') {
            ans += s[i];
        }
        else {
            const int count = read_number(s, ++i);
            const string var = '_' + to_string(k++);
            ans += var;
            vars[var] = count;
            arr.push_back(count);
        }
    }
    return ans;
}

int eval(const string& s, unordered_map<string, int>& vars) {
    stack<int> st;
    stack<char> op;
    for (int i = 0; i < s.size(); ++i) {
        if (delim(s[i])) continue;

        if (s[i] == '(') {
            op.push('(');
        }
        else if (s[i] == ')') {
            while (op.top() != '(') {
                process_op(st, op.top());
                op.pop();
            }
            op.pop();
        }
        else if (is_op(s[i])) {
            const char current_op = s[i];
            while (not op.empty() and priority(op.top()) >= priority(current_op)) {
                process_op(st, op.top());
                op.pop();
            }
            op.push(current_op);
        }
        else if (is_var(s[i])) {
            st.push(read_var(s, i, vars));
        }
        else {
            st.push(read_number(s, i));
        }
    }
    while (not op.empty()) {
        process_op(st, op.top());
        op.pop();
    }
    return st.top();
}

vector<int> eval(const string& s, const vector<int>& arr, const int n, unordered_map<string, int>& vars) {
    if (n == arr.size()) {
        return {eval(s, vars)};
    }
    vector<int> ans;
    for (int i = 1; i <= arr[n]; ++i) {
        const string var = '_' + to_string(n + 1);
        vars[var] = i;
        for (const int value : eval(s, arr, n + 1, vars)) {
            ans.push_back(value);
        }
    }
    return ans;
}

map<int, double> sol(const string& s_) {
    unordered_map<string, int> vars;
    vector<int> arr;
    const string s = pre_handle_dice(s_, vars, arr);
    auto ans = eval(s, arr, 0, vars);

    unordered_map<int, int> count;
    for (int i = 0; i < ans.size(); ++i) {
        ++count[ans[i]];
    }

    map<int, double> percents;
    for (int i = 0; i < ans.size(); ++i) {
        percents[ans[i]] = static_cast<double>(count[ans[i]]) / ans.size();
    }
    return percents;
}

int main() {
    cout << sol("4+2") << endl; // 6
    cout << sol("4-2") << endl; // 2
    cout << sol("d4+2") << endl; // 3 4 5 6
    cout << sol("(d4+2)+1") << endl; // 4 5 6 7
    cout << sol("d5+2") << endl; // 3 4 5 6 7
    cout << sol("d2+2+d2") << endl; // 4 5 6
    cout << sol("d2+2+d4") << endl; // 4 5 6
    cout << sol("d6>2") << endl; // 0 1
    cout << sol("d2+(d2+2+d4+3+d4)*3-5+d8-1") << endl; // 0 1
}
