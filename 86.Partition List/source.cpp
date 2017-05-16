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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesser = new ListNode(-1);
        ListNode* greater = new ListNode(-1), *g2 = greater, *l2 = lesser;
        ListNode* n = head, *tmp;
        while(n)
        {
            if(n->val < x)
            {
                lesser->next = n;
                lesser = lesser->next;
            }
            else
            {
                greater->next = n;
                greater = greater->next;
            }
            tmp = n;
            n = n->next;
            tmp->next = NULL;
        }
        lesser->next = g2->next;
        return l2->next;
    }
};