#include "../../template.hpp"

int is_prime(int n) { // O(sqrt(n))
    if (n == 1) return 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

vector<int> sieve_primes(int a, int b) { // O(logn)
    vector<bool> is_prime(b + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= b; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= b; i += p) {
                is_prime[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = a; i <= b; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

unordered_map<int, int> prime_factorization(int n) { // O(sqrt(n))
    unordered_map<int, int> primes;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                ++count;
                n /= i;
            }
            primes.insert({i, count});
        }
    }
    if (n > 1) primes.insert({n, 1});
    return primes;
}

unordered_map<int, int> prime_factorization_sieve(int n) { // O(logn)
    vector<int> is_prime(n + 1, -1);
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p] == -1) {
            for (int i = p * p; i <= n; i += p) {
                if (is_prime[i] == -1) {
                    is_prime[i] = p;
                }
            }
        }
    }
    unordered_map<int, int> primes;
    for (; is_prime[n] != -1; n /= is_prime[n]) {
        ++primes[is_prime[n]];
    }
    ++primes[n];
    return primes;
}

int power(int base, int p) { // O(logn) // binary exponentiation
    int res = 1;
    while (p > 0) {
        if (p & 1) res *= base, --p;
        else base *= base, p /= 2;
    }
    return res;
}

int power_mod(int base, int p, int mod) { // O(logn)
    int res = 1;
    while (p > 0) {
        if (p & 1) res *= base, res %= mod, --p;
        else base *= base, base %= mod, p /= 2;
    }
    return res;
}

vector<vector<int>> mul_matrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    const int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<vector<int>> power_matrix(vector<vector<int>> A, int p) {
    const int n = A.size();
    vector<vector<int>> I(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        I[i][i] = 1;
    }
    while (p > 0) {
        if (p & 1) I = mul_matrix(I, A), --p;
        else A = mul_matrix(A, A), p /= 2;
    }
    return I;
}

int64_t add_mod(int64_t a, int64_t b, int64_t mod = 1e9 + 7) {
    return (a % mod + b % mod) % mod;
}

int64_t sub_mod(int64_t a, int64_t b, int64_t mod = 1e9 + 7) {
    return (a % mod - b % mod + mod) % mod;
}

int64_t mul_mod(int64_t a, int64_t b, int64_t mod = 1e9 + 7) {
    return ((a % mod) * (b % mod)) % mod;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() { TimeMeasure _;
    cout << "is_prime:" << endl;
    cout << is_prime(7) << endl; // 1
    cout << is_prime(11) << endl; // 1
    cout << is_prime(12) << endl; // 0
    cout << is_prime(25) << endl; // 0
    cout << endl;

    cout << "sieve_primes:" << endl;
    cout << sieve_primes(0, 11) << endl; // 2 3 5 7 11
    cout << endl;

    cout << "prime_factorization:";
    cout << prime_factorization(21) << endl; // 7: 1, 3: 1
    cout << prime_factorization(2358811) << endl; // 23: 2, 13: 1, 7: 3
    cout << endl;

    cout << "prime_factorization_sieve:";
    cout << prime_factorization_sieve(21) << endl; // 7: 1, 3: 1
    cout << prime_factorization_sieve(2358811) << endl; // 23: 2, 13: 1, 7: 3
    cout << endl;

    cout << "power:" << endl;
    cout << power(2, 13) << endl; // 8192
    cout << endl;

    cout << "matrix exponentiation:";
    cout << power_matrix(
        {{1,0}, // 1 0
         {1,1}}, // 3 1
        3) << endl;
    cout << power_matrix(
        {{1,0,4}, // 17 112 116
         {1,2,2}, // 15 88 100
         {0,4,4}}, // 28 144 160
        3) << endl;

    cout << "gcd:" << endl;
    cout << gcd(140, 12) << endl; // 4
}
