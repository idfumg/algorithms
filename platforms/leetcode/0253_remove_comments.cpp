#include "../../template.hpp"

vs sol(const vs& arr) {
    string temp;
    bool is_group_comment = false;
    bool was_added_something = false;
    for (const string& line : arr) {
        bool need_add_newline = true;
        for (int i = 0; i < line.size(); ++i) {
            if (is_group_comment) {
                if (i + 1 < line.size() and line[i] == '*' and line[i + 1] == '/') {
                    is_group_comment = false;
                    ++i;
                    if (i == line.size() - 1 and was_added_something) {
                        temp += '\n';
                        need_add_newline = false;
                        need_add_newline = false;
                    }
                }
                else {
                    continue;
                }
            }
            else {
                if (i + 1 < line.size() and line[i] == '/' and line[i + 1] == '/') {
                    need_add_newline = was_added_something;
                    i = line.size() - 1;
                }
                else if (i + 1 < line.size() and line[i] == '/' and line[i + 1] == '*') {
                    is_group_comment = true;
                    need_add_newline = was_added_something;
                    ++i;
                }
                else {
                    temp += line[i];
                    was_added_something = true;
                }
            }
        }
        if (need_add_newline and was_added_something and not is_group_comment) {
            temp += '\n';
            was_added_something = false;
        }
    }
    istringstream is(temp);
    string line;
    vs ans;
    while (getline(is, line, '\n')) {
        ans.push_back(line);
    }
    for (const string& s : ans) cout << "'" << s << "'" << endl; cout << endl;
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"}) << endl; // ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
    cout << sol({"a/*comment", "line", "more_comment*/b"}) << endl; // ["ab"]
    cout << sol({"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"}) << endl; // ["struct Node{","    ","    int size;","    int val;","};"]
    cout << sol({"main() {", "   func(1);", "   /** / more comments here", "   float f = 2.0", "   f += f;", "   cout << f; */", "}"}) << endl; // ["main() {","   func(1);","   ","}"]
    cout << sol({"class test{", "public: ", "   int x = 1;", "   /*double y = 1;*/", "   char c;", "};"}) << endl; // ["class test{","public: ","   int x = 1;","   ","   char c;","};"]
}
