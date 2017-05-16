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
    ListNode* MergeSortedLists(ListNode* a, ListNode* b)
    {
        ListNode * d = new ListNode(-1);
        ListNode *head = d;
        while(a && b)
        {
            if(a->val <= b->val)
            {
                d->next = a;
                a = a->next;
            }
            else
            {
                d->next = b;
                b = b->next;
            }
            d = d->next;
        }
        if(a)d->next = a;
        else d->next = b;
        return head->next;
    }
    
    ListNode* sortList(ListNode* L)
    {
        if( (L == NULL) || (L->next == NULL))
        {
            return L;
        }
        
        ListNode* fast = L, *slow = L, *ps = NULL;
        while(fast && fast->next)
        {
            ps = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        ps->next = NULL;
        return MergeSortedLists(sortList(L), sortList(slow));
    }
    
};