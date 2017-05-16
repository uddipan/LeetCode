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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p= head, *prev = dummy, *q, *r;
        while (p && p->next)
        {
            q = p->next;
            r = q->next;
            prev->next = q;
            q->next = p;
            p->next = r;
            prev = p;
            p = r;
        }
        return dummy->next;
    }
};