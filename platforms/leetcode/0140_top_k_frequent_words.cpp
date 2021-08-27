#include "../../template.hpp"

vector<string> sol(const vector<string>& arr, const int K) {
    unordered_map<string, int> count;
    for (const string& word : arr) {
        ++count[word];
    }
    vector<string> words;
    vector<int> freqs;
    for (const auto& [word, freq] : count) {
        words.push_back(word);
        freqs.push_back(freq);
    }
    vi idxs(freqs.size());
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&](const int i, const int j) {
        if (freqs[i] == freqs[j]) return words[i] < words[j];
        return freqs[i] > freqs[j];
    });
    vector<string> ans;
    for (int i = 0, k = K; k > 0 and i < idxs.size(); ++i, --k) {
        ans.push_back(words[idxs[i]]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << sol({"i","love","leetcode","i","love","coding"}, 2) << endl; // "i","love"
    cout << sol({"the","day","is","sunny","the","the","the","sunny","is","is"}, 4) << endl; // "the","is","sunny","day"
}
