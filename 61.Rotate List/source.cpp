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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return head;
        int p=0; ListNode *tail = head;
        while(tail)
        {
            p++;
            tail = tail->next;
        }
        k = k%p;
        
        if(k == 0)return head;
        
        
        
        int cnt = p-k;
        ListNode *n = head, *prev;
        while(cnt--)
        {
            prev = n;
            n = n->next;
        }
        
        ListNode *m = n;
        while(m->next)
        {
            m = m->next;
        }
        
        m->next = head;
        prev->next = NULL;
        return n;
    }
};