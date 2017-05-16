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
    void rev(ListNode* &head, ListNode* &tail)
    {
        ListNode* prev = NULL,*p=head,*tmp;
        while(p != tail)
        {
            tmp = p->next;
            p->next = prev;
            prev = p;
            p=tmp;
        }
        p->next = prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)return head;
        int cnt = 1;
        ListNode*h,*t,*p=head, *prevNode,*prev=new ListNode(-1),*nextnode;
        prevNode = prev;
        ListNode*dummy = prev;
        prev->next = head;
        
        while(p)
        {
            if(cnt == m)
            {
                h = p;
                prevNode = prev;
            }
            if(cnt == n)
            {
                t = p;
                nextnode = p->next;
            }
            prev = p;
            p = p->next;
            cnt++;
        }
        rev(h,t);
        prevNode->next = t;
        h->next = nextnode;
        return dummy->next;
    }
};