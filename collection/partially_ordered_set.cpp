#include "../template.hpp"

using namespace std;

struct Node1 {
public:
    int value;
    vector<Node1*> kids;

public:
    Node1(const int value) noexcept : value(value) {}
    ~Node1() { }

public:
    bool isConditionSatisfied(const Node1* current) const noexcept {
        return value != current->value and current->value % value == 0;
    }

    bool update(Node1* current) noexcept {
        if (not isConditionSatisfied(current)) {
            return false;
        }
        bool updated = false;
        for (const auto& kid : kids) {
            if (kid->update(current)) {
                updated = true;
            }
        }
        if (not updated) {
            kids.push_back(current);
        }
        return true;
    }
};

void dfs(const Node1* root, vector<int>& path, vector<int>& res) noexcept {
    path.push_back(root->value);
    if (root->kids.empty() and path.size() > res.size()) {
        res = path;
    }
    for (const auto& kid : root->kids) {
        dfs(kid, path, res);
    }
    path.pop_back();
}

vector<int> solve(vector<int>& nums) {
    if (nums.empty()) return {};
    sort(nums.begin(), nums.end());

    Node1* root = new Node1(1);
    for (const int num : nums) {
        root->update(new Node1(num));
    }

    vector<int> path;
    vector<int> res;
    dfs(root, path, res);
    delete root;

    if (nums[0] == 1) {
        return res;
    }

    return vector<int>(res.begin() + 1, res.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    {
        vector<int> nums{1,2,3};
        cout << solve(nums) << endl;
    }
    {
        vector<int> nums{1,2,4,8};
        cout << solve(nums) << endl;
    }
    {
        vector<int> nums{1,2,3,4,6,24};
        cout << solve(nums) << endl;
    }
    {
        vector<int> nums{3,4,16,8};
        cout << solve(nums) << endl;
    }
    {
        vector<int> nums{4,8,10,240};
        cout << solve(nums) << endl;
    }

    return 0;
}
