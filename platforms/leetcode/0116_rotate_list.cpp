#include "../../template.hpp"

ostream& operator<<(ostream& os, ListNode* head) { print_list2(head); return os; }

int get_list_size(ListNode* head) {
    int ans = 0;
    for (; head; head = head->next) {
        ++ans;
    }
    return ans;
}

ListNode* rotate_list(ListNode*& head) {
    ListNode* node = head;
    while (node and node->next and node->next->next) {
        node = node->next;
    }
    node->next->next = head;
    head = node->next;
    node->next = nullptr;
    return head;
}

ListNode* tab_(ListNode* head, const int K) {
    const int n = get_list_size(head);
    if (n == 0) return nullptr;
    const int k = K % n;
    for (int i = 0; i < k; ++i) {
        head = rotate_list(head);
    }
    return head;
}

ListNode* tab(const vi& arr, const int k) {
    ListNode* head = make_list(arr);
    ListNode* ans = tab_(head, k);
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << tab({1,2,3,4,5}, 2) << endl; // 4,5,1,2,3
    cout << tab({0,1,2}, 4) << endl; // 2,0,1
}
