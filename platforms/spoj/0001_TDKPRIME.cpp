//#include "../../template.hpp"

#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

vector<int> sieve_primes(int a, int b) {
    const vector<bool> is_prime = sieve(b);
    vector<int> primes;
    for (int i = 1; i <= b; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

void sol(istream& is = std::cin) {
    const vector<int> primes = sieve_primes(2, 90000001);

    int n; is >> n;
    while (n--) {
        int k; is >> k;
        cout << primes[k - 1] << '\n';
    }
}

void sol(const string& input) {
    istringstream is(input);
    sol(is);
    cout << endl;
}

int main() { //TimeMeasure _; __x();
    static const string input1 = R"(
7
1
10
100
1000
10000
100000
1000000
)";
    sol(input1);
}

// int main() {
//     sol(std::cin);
// }
