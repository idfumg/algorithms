#include "../../template.hpp"

bool is_op(const string& s) {
    return s.size() == 1 and (s[0] == '+' or s[0] == '-' or s[0] == '/' or s[0] == '*');
}

bool is_number(const string& s) {
    if (is_op(s)) return false;
    for (const char ch : s) {
        if (ch == '-') continue;
        if (ch < '0' and ch > '9') return false;
    }
    return true;
}

int apply_op(const int left, const int right, const string& op) {
    switch (op[0]) {
    case '-': return left - right;
    case '+': return left + right;
    case '*': return left * right;
    case '/': return left / right;
    }
    throw std::runtime_error("Wrong operation!: " + op);
}

int sol(const vs& exp) {
    stack<int> st;
    for (const string& value : exp) {
        if (is_number(value)) {
            st.push(stoi(value));
        }
        else if (is_op(value)) {
            const int right = st.top(); st.pop();
            const int left = st.top(); st.pop();
            const int res = apply_op(left, right, value);
            st.push(res);
        }
        else {
            throw std::runtime_error("Wrong operand!: " + value);
        }
    }
    return st.empty() ? 0 : st.top();
}

int main() { TimeMeasure _; __x();
    cout << sol({"2","1","+","3","*"}) << endl; // 9
    cout << sol({"4","13","5","/","+"}) << endl; // 6
    cout << sol({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) << endl; // 22
}
