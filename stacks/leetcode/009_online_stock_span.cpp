#include "../../template.hpp"

class StockSpanner {
private:
    deque<vi> mq;

public:
    StockSpanner(){}
    int next(const int price) {
        int length = 1;
        while (not mq.empty() and price >= mq.back()[0]) {
            length += mq.back()[1];
            mq.pop_back();
        }
        mq.push_back({price, length});
        return length;
    }
};

int tab(const vi& values) {
    StockSpanner spanner;
    for (const int value : values) {
        cout << spanner.next(value) << ' ';
    }
    return INF;
}

int main() { TimeMeasure _; __x();
    cout << tab({100,80,60,70,60,75,85}) << endl; // 1,1,1,2,1,4,6
}
