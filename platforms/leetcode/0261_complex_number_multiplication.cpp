#include "../../template.hpp"

struct Complex {
    int x = 0;
    int y = 0;
};

Complex operator+(const Complex& lhs, const Complex& rhs) {
    const int p1 = lhs.x * rhs.x;
    const int p2 = lhs.y * rhs.y;
    const int p3 = (lhs.x + lhs.y) * (rhs.x + rhs.y);
    const int real = p1 - p2;
    const int imaginary = p3 - (p1 + p2);
    return Complex{real, imaginary};
}

ostream& operator<<(ostream& os, const Complex& a) {
    return os << a.x << '+' << a.y << 'i';
}

int read_number(const string& s, int& i) {
    const int n = s.size();
    bool negative = false;
    if (i < n and s[i] == '-') {
        negative = true;
        ++i;
    }
    int ans = 0;
    for (; i < n and s[i] - '0' >= 0 and s[i] - '0' <= 9; ++i) {
        ans = ans * 10 + s[i] - '0';
    }
    ++i;
    return negative ? -ans : ans;
}

Complex read_number(const string& s) {
    const int n = s.size();
    Complex ans;
    int i = 0;
    ans.x = read_number(s, i);
    ans.y = read_number(s, i);
    return ans;
}

string sol(const string& s, const string& t) {
    const Complex a = read_number(s);
    const Complex b = read_number(t);
    const Complex ans = a + b;
    ostringstream os;
    os << ans;
    return os.str();
}

int main() { TimeMeasure _; __x();
    cout << sol("1+1i", "1+1i") << endl; // 0+2i
    cout << sol("1+-1i", "1+-1i") << endl; // 0+-2i
    cout << sol("2+3i", "4+5i") << endl; // -7+22i
    cout << sol("3+7i", "6+2i") << endl; // 4+48i
}
