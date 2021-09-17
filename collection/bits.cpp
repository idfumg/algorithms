#include "../template.hpp"

using namespace std;

int64_t bit_ones(int64_t mask) {
    int64_t count = 0;
    for (; mask; mask &= mask - 1) {
        ++count;
    }
    return count;
}

template<class T = int>
std::vector<std::vector<T>> all_subsets(const std::vector<T>& nums) { // 2^n
    size_t n = nums.size();
    std::vector<std::vector<T>> subsets(1 << n);
    for (size_t i = 0; i < (1 << n); ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subsets[i].push_back(nums[j]);
            }
        }
    }
    return subsets;
}

uint64_t bit_msb(uint64_t mask) {
    if (mask & (1ull << 63ull)) return 1ull << 63ull; // +1 will overflow later
    mask |= mask >> 1; // 2 bits set
    mask |= mask >> 2; // 4 bits set
    mask |= mask >> 4; // 8 bits set
    mask |= mask >> 8; // 16 bits set
    mask |= mask >> 16; // 32 bits set
    mask |= mask >> 31; // 64 bits set
    return (mask + 1) >> 1;
}

uint64_t bit_lsb(uint64_t mask) { return mask & -mask; }
bool is_power_of_2(uint64_t x) { return x and (x & (x - 1)) == 0; }
bool bit_check(uint64_t mask, uint64_t i) { return mask & (1 << i); }
uint64_t bit_set(uint64_t mask, uint64_t i) { return mask |= 1 << i; }
uint64_t bit_clear(uint64_t mask, uint64_t i) { return mask & ~(1 << i); }
uint64_t bit_toggle(uint64_t mask, uint64_t i) { return mask ^ (1 << i); }

int main() {
    cout << is_power_of_2(4) << endl; // 1
    cout << is_power_of_2(8) << endl; // 1
    cout << is_power_of_2(16) << endl; // 1
    cout << is_power_of_2(6) << endl; // 0
    cout << is_power_of_2(5) << endl; // 0
    cout << is_power_of_2(0b11001) << endl; // 0
    cout << endl;
    cout << bit_ones(5) << endl; // 2
    cout << bit_ones(0b11) << endl; // 2
    cout << bit_ones(0b1011) << endl; // 3
    cout << bit_ones(0b10110) << endl; // 3
    cout << bit_ones(0b111001) << endl; // 4
    cout << endl;
    cout << all_subsets({1,2,3}) << endl;//{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}
    cout << endl;
    cout << bit_msb(0b10110101) << endl; // 128 = 2^7
    cout << bit_msb(1 << 7) << endl; // 128 = 2^7
    cout << bit_msb(0b1000000000100000000010000000001000000000100000000010000000001111) << endl; // 9223372036854775808L = 2^63
    cout << bit_msb(0b0100000000100000000010000000001000000000100000000010000000001111) << endl; // 4611686018427387904 = 2^62
    cout << bit_msb(0b0000000000000000000000000000000000000000000000000000000000000001) << endl; // 1 = 2^0
    cout << bit_msb(0b0000000000000000000000000000000000000000000000000000000000000010) << endl; // 2 = 2^1
    cout << endl;
    cout << bit_lsb(0b0101011101000) << endl; // 8 = 2^3
    cout << bit_lsb(1ll << 63ll) << endl; // 9223372036854775808L = 2^63
    cout << endl;
    cout << bit_check(0b10101, 0) << endl; // 1
    cout << bit_check(0b10101, 1) << endl; // 0
    cout << bit_check(0b10101, 2) << endl; // 1
    cout << bit_check(0b10101, 3) << endl; // 0
    cout << bit_check(0b10101, 4) << endl; // 1
    cout << endl;
    cout << bit_set(0b1011001, 5) << endl; // 0b1111001 = 121
    cout << bit_clear(0b1111001, 5) << endl; // 0b1011001 = 89
    cout << bit_toggle(0b1011001, 5) << endl; // 0b1111001 = 121
    cout << bit_toggle(0b1111001, 5) << endl; // 0b1011001 = 89
}
