#include "../../template.hpp"

int sol(string s) {
    int n = s.size();

    vi dp(n + 1);
    dp[0] = 1;

    array<int16_t, 256> prev{};
    memset(prev.data(), -1, sizeof(prev));

    for (int i = 1; i <= n; ++i) {
        int ch = s[i - 1] - '0';
        dp[i] = (2 * dp[i - 1]) % MOD;
        if (prev[ch] != -1) {
            dp[i] -= dp[prev[ch] - 1];
            if (dp[i] < 0) dp[i] += MOD;
        }
        prev[ch] = i;
    }
    return dp[n] - 1;
}

int sol2(string s) {
    int n = s.size();

    vi dp(n + 1);
    dp[0] = 1;

    vi sum(n + 1);
    sum[0] = 1;

    array<int16_t, 256> last{};
    memset(last.data(), -1, sizeof(last));

    for (int i = 1; i <= n; ++i) {
        dp[i] = sum[i - 1] - (last[s[i - 1]] != -1 ? sum[last[s[i - 1]] - 1] : 0);
        if (dp[i] < 0) dp[i] += MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
        last[s[i - 1]] = i;
    }
    return mod(sum[n] - 1);
}

int main() { TimeMeasure _; __x();
    cout << sol("abc") << endl; // 7
    cout << sol("aba") << endl; // 6
    cout << sol("aaa") << endl; // 3
    cout << sol("lee") << endl; // 5
    cout << sol("ggg") << endl; // 3
    cout << sol("ggg123eree1") << endl; // 635
    cout << sol("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn") << endl; // 97915677
    cout << sol("ophajrtskwvemzzpybodijlrnixjzwuhllbteqcnpatxwbfbhyhnhntypjsmiskryyircromuqpflmkjycxxeokajpfcgmhebxqqoftauketrwoocxqflasfmcoivpslmsvafvsjcwabansddjbhhrrelcfrgwgssbuhfjplkpxfdzvjwtmlbphxeasvacwtvslbnpflmlasxqfeegkbgguuawscvuzrfxiaepkvzrrrsnezluebtwcpnivgnetmlrdyytsooumbsnewejceeaajbzpqphghsafysqbzxvda") << endl; // 216384685
    cout << endl;
    cout << sol2("abc") << endl; // 7
    cout << sol2("aba") << endl; // 6
    cout << sol2("aaa") << endl; // 3
    cout << sol2("lee") << endl; // 5
    cout << sol2("ggg") << endl; // 3
    cout << sol2("ggg123eree1") << endl; // 635
    cout << sol2("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn") << endl; // 97915677
    cout << sol2("ophajrtskwvemzzpybodijlrnixjzwuhllbteqcnpatxwbfbhyhnhntypjsmiskryyircromuqpflmkjycxxeokajpfcgmhebxqqoftauketrwoocxqflasfmcoivpslmsvafvsjcwabansddjbhhrrelcfrgwgssbuhfjplkpxfdzvjwtmlbphxeasvacwtvslbnpflmlasxqfeegkbgguuawscvuzrfxiaepkvzrrrsnezluebtwcpnivgnetmlrdyytsooumbsnewejceeaajbzpqphghsafysqbzxvda") << endl; // 216384685
}
