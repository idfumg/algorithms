class CustomStack {
private:
    vector<int> arr;
    int size = 0;

public:
    CustomStack(const int maxSize) {
        arr.reserve(maxSize);
        size = maxSize;
    }

    void push(const int x) {
        if (arr.size() == size) return;
        arr.push_back(x);
    }

    int pop() {
        if (arr.empty()) return -1;
        const int value = arr.back();
        arr.pop_back();
        return value;
    }

    void increment(const int k, const int val) {
        for (int i = 0; i < k and i < arr.size(); ++i) {
            arr[i] += val;
        }
    }
};
