#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class T>
bool is_prime(T n) { // O(sqrt(n))
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // check if it's an even number
    for (T i = 3; i * i <= n; i += 2) { // check only odd numbers
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

template<class T>
vector<T> sieve_primes(T a, T b) { // O(logn)
    if (b < 2) return {};
    vector<bool> is_prime(b + 3);
    is_prime[2] = true;
    for (T p = 3; p <= b; p += 2) {
        is_prime[p] = true;
    }
    for (T p = 3; p * p <= b; p += 2) {
        if (is_prime[p]) {
            for (T i = p * p; i <= b; i += 2 * p) { // mark multiples
                is_prime[i] = false;
            }
        }
    }

    vector<T> primes;
    if (a <= 2) primes.push_back(2);
    for (T i = 3; i <= b; i += 2) {
        if (i >= a and is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

template<class T>
vector<T> segmented_sieve_primes(T a, T b) { // O(logn)
    if (b < 2) return {};
    vector<bool> is_prime(static_cast<T>(sqrt(b)) + 3, false); // [0..sqrt(b)]
    is_prime[2] = true;
    for (T p = 3; p * p <= b; p += 2) {
        is_prime[p] = true;
    }
    for (T p = 3; p * p <= b; p += 2) {
        if (is_prime[p]) {
            for (T i = p * p; i * i <= b; i += 2 * p) { // mark multiples
                is_prime[i] = false;
            }
        }
    }

    vector<bool> is_segmented_prime(b - a + 1, true); // skip [0..a)
    for (T i = 2; i * i <= b; ++i) {
        for (T p = a; p <= b; ++p) {
            if (is_prime[i]) {
                if (i == p) continue;
                if (p % i == 0) {
                    is_segmented_prime[p - a] = false;
                }
            }
        }
    }

    vector<T> primes;
    for (T i = max(2, a); i <= b; ++i) {
        if (is_segmented_prime[i - a]) {
            primes.push_back(i);
        }
    }
    return primes;
}

template<class T>
unordered_map<T, T> prime_factorization(T n) { // O(sqrt(n))
    unordered_map<T, T> primes;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            T count = 0;
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

template<class T>
vector<T> prime_factorization_unique(T n) { // O(sqrt(n))
    vector<T> primes;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            primes.push_back(i);
        }
    }
    if (n > 1) primes.push_back(n);
    return primes;
}

template<class T>
unordered_map<T, T> prime_factorization_sieve(T n) { // O(logn)
    vector<T> is_prime(n + 1, -1);
    for (T p = 2; p * p <= n; ++p) {
        if (is_prime[p] == -1) {
            for (T i = p * p; i <= n; i += p) {
                if (is_prime[i] == -1) { // it's not a prime num
                    is_prime[i] = p; // it can be divided on the prime num `p`
                }
            }
        }
    }
    unordered_map<T, T> primes;
    for (; is_prime[n] != -1; n /= is_prime[n]) { // remove every prime num
        ++primes[is_prime[n]];
    }
    ++primes[n];
    return primes;
}

template<class T>
vector<T> prime_factorization_sieve_unique(T n) { // O(logn)
    vector<T> is_prime(n + 1, -1);
    for (T p = 2; p * p <= n; ++p) {
        if (is_prime[p] == -1) {
            for (T i = p * p; i <= n; i += p) {
                if (is_prime[i] == -1) { // it's not a prime num
                    is_prime[i] = p; // it can be divided on the prime num `p`
                }
            }
        }
    }
    vector<T> primes;
    for (; is_prime[n] != -1; n /= is_prime[n]) {
        if (primes.empty() or primes.back() != is_prime[n]) {
            primes.push_back(is_prime[n]);
        }
    }
    if (primes.back() != n) primes.push_back(n);
    return primes;
}

template<class T>
T power(T base, T p) { // O(logn) // binary exponentiation
    T res = 1;
    while (p > 0) {
        if (p & 1) res *= base, --p;
        else base *= base, p /= 2;
    }
    return res;
}

template<class T>
T power_mod(T base, T p, T mod) { // O(logn)
    T res = 1;
    while (p > 0) {
        if (p & 1) res *= base, res %= mod, --p;
        else base *= base, base %= mod, p /= 2;
    }
    return res;
}

template<class T>
vector<vector<T>> mul_matrix(const vector<vector<T>>& A, const vector<vector<T>>& B) {
    const T n = A.size();
    vector<vector<T>> C(n, vector<T>(n));
    for (T i = 0; i < n; ++i) {
        for (T j = 0; j < n; ++j) {
            for (T k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

template<class T>
vector<vector<T>> power_matrix(vector<vector<T>> A, T p) {
    const T n = A.size();
    vector<vector<T>> I(n, vector<T>(n));
    for (T i = 0; i < n; ++i) {
        I[i][i] = 1;
    }
    while (p > 0) {
        if (p & 1) I = mul_matrix(I, A), --p;
        else A = mul_matrix(A, A), p /= 2;
    }
    return I;
}

template<class T>
T add_mod(T a, T b, T mod = 1e9 + 7) {
    return (a % mod + b % mod) % mod;
}

template<class T>
T sub_mod(T a, T b, T mod = 1e9 + 7) {
    return (a % mod - b % mod + mod) % mod;
}

template<class T>
T mul_mod(T a, T b, T mod = 1e9 + 7) {
    return ((a % mod) * (b % mod)) % mod;
}

template<class T>
T gcd(T a, T b) { // O(logn)
    while (b != 0) {
        T temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

template<class T>
T gcd_rec(T a, T b) { // O(logn)
    return b == 0 ? a : gcd(b, a % b);
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) noexcept {
    for (const auto& value : v) os << value << ' ';
    return os;
}

template<class T, class U>
std::ostream& operator << (std::ostream& os, const std::unordered_map<T, U>& tab) noexcept {
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os;
}

int main() {
    cout << "is_prime:" << endl;
    cout << is_prime(7) << endl; // 1
    cout << is_prime(11) << endl; // 1
    cout << is_prime(12) << endl; // 0
    cout << is_prime(25) << endl; // 0
    cout << endl;

    cout << "sieve_primes:" << endl;
    cout << sieve_primes(0, 11) << endl; // 2 3 5 7 11
    cout << sieve_primes(5, 11) << endl; // 2 3 5 7 11
    cout << sieve_primes(11, 26) << endl; // 11 13 17 19 23
    cout << endl;

    cout << "segmented_sieve_primes:" << endl;
    cout << segmented_sieve_primes(0, 11) << endl; // 2 3 5 7 11
    cout << segmented_sieve_primes(5, 11) << endl; // 5 7 11
    cout << segmented_sieve_primes(11, 26) << endl; // 11 13 17 19 23
    cout << endl;

    cout << "prime_factorization:" << endl;
    cout << prime_factorization(21) << endl; // 7: 1, 3: 1
    cout << prime_factorization(2358811) << endl; // 23: 2, 13: 1, 7: 3
    cout << endl;

    cout << "prime_factorization_unique:" << endl;
    cout << prime_factorization_unique(21) << endl; // 7, 3
    cout << prime_factorization_unique(2358811) << endl; // 23, 13, 7
    cout << endl;

    cout << "prime_factorization_sieve:" << endl;
    cout << prime_factorization_sieve(21) << endl; // 7: 1, 3: 1
    cout << prime_factorization_sieve(2358811) << endl; // 23: 2, 13: 1, 7: 3
    cout << endl;

    cout << "prime_factorization_sieve_unique:" << endl;
    cout << prime_factorization_sieve_unique(21) << endl; // 7, 3
    cout << prime_factorization_sieve_unique(2358811) << endl; // 23, 13, 7
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
    cout << gcd(12, 20) << endl; // 4
    cout << gcd(18, 68) << endl; // 2
    cout << gcd_rec(140, 12) << endl; // 4
    cout << gcd_rec(12, 20) << endl; // 4
    cout << gcd_rec(18, 68) << endl; // 2
}
