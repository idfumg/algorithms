#include "../../template.hpp"

string sol(const string& s, const unordered_set<string>& banned) {
    string temp;
    unordered_map<string, int> freq;
    istringstream is(s);
    while (getline(is, temp, ' ')) {
        istringstream is2(temp);
        string temp2;
        while (getline(is2, temp2, ',')) {
            for_each(temp2.begin(), temp2.end(), [](char& ch){ch = tolower(ch);});
            while (not temp2.empty() and not isalpha(temp2.back())) temp2.pop_back();
            ++freq[temp2];
        }
    }
    int maxi = 0;
    string ans = "";
    for (const auto& [word, count] : freq) {
        if (count > maxi and not banned.count(word)) {
            ans = word;
            maxi = count;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol("Bob hit a ball, the hit BALL flew far after it was hit.", {"hit"}) << endl; // ball
    cout << sol("a.", {}) << endl; // a
    cout << sol("a, a, a, a, b,b,b,c, c", {"a"}) << endl; // b
}
