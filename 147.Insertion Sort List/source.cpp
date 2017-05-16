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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)return head;
        ListNode* p = head, *q = head, *tmp, *curr;
        int minSoFar = INT_MAX;
        while(p)
        {
            //tmp = p->next;
            q = p;
            minSoFar = INT_MAX;
            while(q)
            {
                if(q->val < minSoFar)
                {
                    minSoFar = q->val;
                    curr = q;
                }
                q = q->next;
            }
            //swap
            int tv = curr->val;
            curr->val = p->val;
            p->val = tv;
            p = p->next;
        }
        return head;
    }
};