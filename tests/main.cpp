//#include "../template.hpp"
#include <vector>
#include <string>
#include <random>
#include <iostream>

#define _0_9 "0123456789"
#define _A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define _a_z "abcdefghijklmnopqrstuvwxyz"
#define _ALNUMS _0_9 _A_Z _a_z

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& values) {
    for (const auto& value : values) os << value << ' ';
    return os;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<T>>& values) {
    for (const auto& value : values) os << value << std::endl;
    return os;
}

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

int main() {
    std::cout << random_number(-9, 9) << std::endl;
    std::cout << random_numbers<std::uint16_t>(20, 0, 9) << std::endl;
    std::cout << random_matrix<std::int64_t>(8, 8, 0, 1) << std::endl;
    std::cout << random_string(6, _0_9 _a_z _A_Z) << std::endl;
    std::cout << random_strings(6, 6, _a_z) << std::endl;
    std::cout << random_matrix(8, 8, _a_z) << std::endl;
}
