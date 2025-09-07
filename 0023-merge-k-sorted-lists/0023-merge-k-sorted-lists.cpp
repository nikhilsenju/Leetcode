/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Merge two sorted lists
    ListNode* merge(ListNode* prev, ListNode* cur) {
        ListNode dummy(-1); // Dummy node to simplify list construction
        ListNode* head = &dummy;

        while (prev != nullptr && cur != nullptr) {
            if (prev->val > cur->val) {
                head->next = cur;
                cur = cur->next;
            } else {
                head->next = prev;
                prev = prev->next;
            }
            head = head->next;
        }

        // Attach the remaining part
        if (prev != nullptr)
            head->next = prev;
        if (cur != nullptr)
            head->next = cur;

        return dummy.next;
    }

    // Merge k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* prev = nullptr;

        for (auto cur : lists) {
            if (!cur) continue; // Skip empty lists
            if (!prev) {
                prev = cur; // For the first list, just set prev = cur
            } else {
                prev = merge(prev, cur); // Merge with the accumulated list
            }
        }

        return prev;
    }
};
