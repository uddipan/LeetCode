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
    pair<ListNode*, ListNode*> rev(ListNode *L, ListNode* R)
    {
        if(L == R)
        {
            return make_pair(L,R);
        }
        ListNode* start = L->next, *prev = L, *tmp;
        while(start != R)
        {
            tmp = start->next;
            start->next = prev;
            prev = start;
            start = tmp;
        }
        start->next = prev;
        return make_pair(start,L);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *L = new ListNode(-1);
        L->next = head;
        ListNode *R = head, *prev = L;
        int cnt = 0;
        bool first = true;
        while(1)
        {
            while(R && (cnt < k))
            {
                cnt ++;
                R = R->next;
                prev = prev->next;
            }
            if((cnt <k) && (R == NULL))break;
            pair<ListNode*, ListNode*>P = rev(L->next,prev);
            L->next = P.first;
            P.second->next = R;
            L = P.second;
            prev = L;
            R = L->next;
            cnt=0;
            if(first) {head = P.first; first = false;}
        }
        return head;
    }
};