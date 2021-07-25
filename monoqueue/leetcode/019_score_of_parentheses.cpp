#include "../../template.hpp"

int tab(const string& s) {
    const int n = s.size();
    deque<int> mq;
    int current = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            mq.push_back(current);
            current = 0;
        }
        else {
            current = max(2 * current, 1) + mq.back();
            mq.pop_back();
        }
    }
    return current;
}

int tab2(const string& s) {
    const int n = s.size();
    int layers = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++layers;
        else --layers;
        if (s[i] == ')' and s[i - 1] == '(') ans += 1 << layers;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab("()") << endl; // 1
    cout << tab("(())") << endl; // 2
    cout << tab("((()))") << endl; // 4
    cout << tab("()()") << endl; // 2
    cout << tab("(()(()))") << endl; // 6
    cout << endl;
    cout << tab2("()") << endl; // 1
    cout << tab2("(())") << endl; // 2
    cout << tab2("((()))") << endl; // 4
    cout << tab2("()()") << endl; // 2
    cout << tab2("(()(()))") << endl; // 6
}
