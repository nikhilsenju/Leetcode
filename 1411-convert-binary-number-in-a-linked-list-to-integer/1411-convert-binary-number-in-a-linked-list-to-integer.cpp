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
    int getDecimalValue(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * cur = head;
        while(cur){
            ListNode * next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        int ans = 0;
        int i = 0;
        while(prev){
            if(prev->val==1){
                ans+=(1<<i);
            }
            i++;
            prev = prev->next;
        }
        return ans;
    }
};