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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* n = head, *tmp, *ret = prev;
        while(n && n->next)
        {
            tmp = n->next;
            while(n->next && n->val == n->next->val)
            {
                n->next = n->next->next;
            }
            if(tmp == n->next)
            {
                prev = n;
            }
            else
            {
                prev->next = n->next;
            }
            n = n->next;
        }
        return ret->next;
    }
};