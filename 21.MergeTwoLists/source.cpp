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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * P = new ListNode(0);
        ListNode *Q = P;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                P->next = l1;
                l1 = l1->next;
            }
            else
            {
                P->next = l2;
                l2 = l2->next;
            }
            P = P->next;
        }
        if(l1)P->next = l1;
        if(l2) P->next = l2;
        return Q->next;
    }
};