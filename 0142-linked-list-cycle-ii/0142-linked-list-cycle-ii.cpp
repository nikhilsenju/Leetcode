/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        int fl = 0;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                fl=1;
                break;
            }
        }
        if(!fl){
            return nullptr;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast = fast->next;
        }
        return slow;
        
    }

};