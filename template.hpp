#pragma once

#include <bits/stdc++.h>
#include "template_tree.hpp"

using namespace std;

constexpr double PI = 3.1415926535897932384626433832795;
constexpr double EPS = 0.0000000001;
constexpr long long INFLL = 1000000000000000000 + 7;
constexpr int INF = 1000000000 + 7;
constexpr int null = -INF;
constexpr int MOD = 1000000000 + 7;

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vvvb = std::vector<vvb>;
using vc = std::vector<char>;
using vvc = std::vector<vc>;
using vs = std::vector<string>;
using vvs = std::vector<vs>;

using ll = std::int64_t;
using ull = std::uint64_t;

template<class T>
std::ostream& operator << (std::ostream& os, const std::pair<T, T>& p) noexcept {
    return os << p.first << ',' << p.second;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<std::pair<T, T>>& v) noexcept {
    for (const auto& value : v) os << '{' << value.first << ',' << value.second << '}' << ' ';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::deque<T>& v) noexcept {
    for (const auto& value : v) os << value << ' ';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) noexcept {
    for (const auto& value : v) os << value << ' ';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v) noexcept {
    os << '\n';
    for (const auto& L : v) os << L << endl;
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::multiset<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::unordered_set<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os;
}

template<class T, class U>
std::ostream& operator << (std::ostream& os, const std::map<T, U>& tab) noexcept {
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os;
}

template<class T, class U>
std::ostream& operator << (std::ostream& os, const std::unordered_map<T, U>& tab) noexcept {
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::stack<T>& v) noexcept {
    for (auto temp = v; not temp.empty(); temp.pop()) os << temp.top() << ' ';
    return os;
}

template<class T>
std::ostream& operator << (std::ostream& os, const std::queue<T>& v) noexcept {
    for (auto temp = v; not temp.empty(); temp.pop()) os << temp.front() << ' ';
    return os;
}

template<class ... T>
std::ostream& operator << (std::ostream& os, const std::priority_queue<T...>& v) noexcept {
    for (auto temp = v; not temp.empty(); temp.pop()) os << temp.top() << ' ';
    return os;
}

class TimeMeasure final {
    std::time_t start;

public:
    TimeMeasure() noexcept
        : start(clock())
    {

    }
    ~TimeMeasure() noexcept {
        std::cerr << "\nExecution time: " << ms() << " ms.\n";
    }
    double ms() const noexcept {
        const auto stop = clock();
        const auto elapsed = static_cast<double>(stop) - start;
        const auto ns = elapsed / CLOCKS_PER_SEC;
        const auto ms = ns * static_cast<double>(1000.0);
        return ms;
    }
    friend std::ostream& operator<<(std::ostream& os, const TimeMeasure& tm) {
        return os << "\nElapsed time: " << tm.ms() << " ms.\n";
    }
};

template<class T>
void ruffle_sort(T& arr) { // qsort O(n^2) has complexity if elements are sorted
    random_shuffle(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
}

#define _0_9 "0123456789"
#define _A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define _a_z "abcdefghijklmnopqrstuvwxyz"
#define _ALNUMS _0_9 _A_Z _a_z

template<class T>
T random_number(const T from, const T to) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<T> distribution{from, to};
    return distribution(generator);
}

template<class T>
std::vector<T> random_numbers(const std::size_t n, const T from, const T to) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<T> distribution{from, to};
    std::vector<T> numbers(n);
    for (std::size_t i = 0; i < n; ++i) {
        numbers[i] = distribution(generator);
    }
    return numbers;
}

template<class T>
std::vector<std::vector<T>> random_matrix(const std::size_t m, const std::size_t n, const T from, const T to) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<T> distribution{from, to};
    std::vector<std::vector<T>> matrix(m, std::vector<T>(n));
    for (std::size_t i = 0; i < m; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            matrix[i][j] = distribution(generator);
        }
    }
    return matrix;
}

std::vector<std::vector<char>> random_matrix(const std::size_t m, const std::size_t n, const std::string_view& chars) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<std::size_t> distribution{0, chars.size() - 1};
    std::vector<std::vector<char>> matrix(m, std::vector<char>(n));
    for (std::size_t i = 0; i < m; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            matrix[i][j] = chars[distribution(generator)];
        }
    }
    return matrix;
}

std::string random_string(const std::size_t n, const std::string_view& chars) {
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<std::size_t> distribution{0, chars.size() - 1};
    std::string s(n, ' ');
    for (std::size_t i = 0; i < n; ++i) {
        s[i] = chars[distribution(generator)];
    }
    return s;
}

std::vector<std::string> random_strings(const std::size_t m, const std::size_t n, const std::string_view& chars) {
    std::vector<std::string> strings;
    for (std::size_t i = 0; i < m; ++i) {
        strings.push_back(random_string(n, chars));
    }
    return strings;
}

#define debug(VarName) {std::cerr << "'" << #VarName << "': " << std::boolalpha << (VarName) << ' ';}
#define debugn(VarName) {std::cerr << "'" << #VarName << "': " << std::boolalpha << (VarName) << std::endl;}
#define trace(Text) std::cout << "Line: " << __LINE__ << " [" << Text << "]" << std::endl;

const int fastio = ([](){std::ios_base::sync_with_stdio(0); std::cin.tie(0);return 0;})();
