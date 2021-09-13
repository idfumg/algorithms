#include "../../template.hpp"

using namespace std::literals::string_literals;
using namespace std;

bool delim(const char c) {
    return c == ' ';
}

bool is_op(const char c) {
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '>';
}

int priority(const char op) {
    if (op == '+' or op == '-') return 1;
    if (op == '*' or op == '/') return 2;
    if (op == '>') return 3;
    return -1;
}

void process_op(stack<ll>& st, const char op) {
    const ll r = st.top(); st.pop();
    const ll l = st.top(); st.pop();
    switch (op) {
    case '+': st.push(l + r); return;
    case '-': st.push(l - r); return;
    case '*': st.push(l * r); return;
    case '/': st.push(l / r); return;
    case '>': st.push(l > r); return;
    }
    throw std::runtime_error("Error: wrong value of operand: "s + op);
}

ll read_number(const string& s, int& i) {
    ll number = 0;
    for (; i < s.size() and isalnum(s[i]); ++i) {
        number = number * 10 + s[i] - '0';
    }
    --i;
    return number;
}

ll eval(const string& s) {
    stack<ll> st;
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
        else if (is_op(s[i]) and not st.empty()) {
            const char current_op = s[i];
            while (not op.empty() and priority(op.top()) >= priority(current_op)) {
                process_op(st, op.top());
                op.pop();
            }
            op.push(current_op);
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

ll sol(const string& s) {
    return eval(s);
}

int main() { TimeMeasure _; __x();
    cout << sol("1 + 1") << endl; // 2
    cout << sol(" 2-1 + 2 ") << endl; // 3
    cout << sol("(1+(4+5+2)-3)+(6+8)") << endl; // 23
    cout << sol("2147483647") << endl; // 2147483647
    cout << sol("-2+ 1") << endl; // -1
}
