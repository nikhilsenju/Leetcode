class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        
        // Collect values from all lists
        for (auto i : lists) {
            ListNode* start = i;
            while (start != nullptr) {
                v.push_back(start->val);
                start = start->next;
            }
        }

        // Edge case: If no elements were found
        if (v.empty()) return nullptr;

        // Sort the collected values
        sort(v.begin(), v.end());

        // Create the merged sorted list
        ListNode* head = new ListNode(v[0]);
        ListNode* tmp = head;
        for (int i = 1; i < v.size(); i++) {
            tmp->next = new ListNode(v[i]);
            tmp = tmp->next;
        }

        return head;
    }
};
