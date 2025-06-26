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
    ListNode * reverse(ListNode * head){
        ListNode * cur = head;
        ListNode * prev = NULL;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        int len = 0;
        while(true){
            if(fast==NULL){
                len = 0;
                break;
            }
            if(fast->next==NULL){
                len = 1;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        if(len){
            slow = slow->next;
        }
        ListNode * mid = reverse(slow);
        ListNode * start = head;
        while(mid!=NULL){
            if(mid->val!=start->val){
                return false;
            }
            mid = mid->next;
            start = start->next;
        }
        return true;




        
    }
};