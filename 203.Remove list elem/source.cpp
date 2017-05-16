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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *p = head;
        
        while(p)
        {
            if(p->val == val)
            {
                prev->next = p->next;
            }
            else
            {
                prev = p;
            }
            p = p->next;
        }
        
        return dummy->next;
        
    }
};