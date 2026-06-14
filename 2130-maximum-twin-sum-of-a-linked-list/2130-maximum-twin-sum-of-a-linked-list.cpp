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
    ListNode* reverse(ListNode *node){
        ListNode * curr = node;
        ListNode * prev = NULL;
        while(curr!=NULL){
            ListNode * nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode * s = head;
        ListNode * f = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode * mid = reverse(s);
        int maxi = 0;
        while(mid){
            maxi = max(maxi,mid->val+head->val);
            head=head->next;
            mid=mid->next;
        }
        return maxi;
    }

};