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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)return head;
        ListNode *odd = head, *even = head->next, *p = head, *prev = NULL;
        bool b = true;
        while(p->next)
        {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            prev = p;
            p = tmp;
            b = !b;
        }
        if(b)
        {
            p->next = even;
        }
        else
        {
            prev->next = even;
        }
        
        return head;
    }
};