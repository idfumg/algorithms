//#define LOCAL_MACHINE

#ifdef LOCAL_MACHINE
#include "../../template.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void sol(istream& is) {
    int64_t n, x; is >> n >> x;
    vector<int64_t> nums(n); for (int64_t i = 0; i < n; ++i) is >> nums[i];

    int64_t count = 0;
    for (int64_t i = 0; i < n - 1; ++i) {
        int64_t current = nums[i] + nums[i + 1] - x;
        if (current > 0) {
            if (nums[i + 1] >= current) {
                count += current;
                nums[i + 1] -= current;
            }
            else {
                count += nums[i + 1];
                current -= nums[i + 1];
                nums[i + 1] = 0;

                if (current > 0) {
                    if (nums[i] >= current) {
                        count += current;
                        nums[i] -= current;
                    }
                    else {
                        count += nums[i];
                        nums[i] = 0;
                    }
                }
            }
        }
    }
    cout << count;
}

#ifdef LOCAL_MACHINE

int main() { //TimeMeasure _; __x();
    static const string inputs[] = {
        R"(
3 3
2 2 2
)",
        R"(
6 1
1 6 1 2 0 4
)",
        R"(
5 9
3 1 4 1 5
)",
        R"(
2 0
5 5
)"
    };

    for (const auto& input : inputs) {
        istringstream is(input);
        sol(is);
        cout << endl;
    }
}

#else

int main() {
    sol(std::cin);
}

#endif // LOCAL_MACHINE
