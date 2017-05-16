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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)return NULL;
        int lenA = 0, lenB = 0;
        ListNode* p = headA, *q;
        while(p)
        {
            p = p->next;
            lenA++;
        }
        p = headB;
        while(p)
        {
            p = p->next;
            lenB++;
        }
        
        int tmp;
        if(lenA > lenB)
        {
            p = headA;
            q = headB;
            tmp = lenA - lenB;
        }
        else
        {
            p = headB;
            q = headA;
            tmp = lenB - lenA;
        }
        while(tmp--)p = p->next;
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};