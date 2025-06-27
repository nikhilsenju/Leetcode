class Solution {
public:
    ListNode * reverse(ListNode * st, int tt, int cur, int k){
        if(st == NULL || cur >= tt) return st;

        ListNode * curstart = st;
        ListNode * prev = nullptr;
        ListNode * reftonext = NULL;
        int origK = k;

        while(k-- && curstart){
            reftonext = curstart->next;
            curstart->next = prev;
            prev = curstart;
            curstart = reftonext;
        }

        st->next = reverse(reftonext, tt, cur + 1, origK);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * tmp = head;
        int count = 0;
        while(tmp){
            count++;
            tmp = tmp->next;
        }

        int tt = count / k;
        return reverse(head, tt, 0, k);
    }
};
