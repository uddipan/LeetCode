/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // interleave the original list and then disassociate
        if(head == NULL)return head;
        RandomListNode* r = head, *tmp;
        
        while(r)
        {
            tmp = new RandomListNode(r->label);
            tmp->next = r->next;
            r->next = tmp;
            r = tmp->next;
        }
        
        r = head;
        while(r)
        {
            if(r->random)r->next->random = r->random->next;
            r = r->next->next;
        }
        
        RandomListNode *prev = head, *curr = prev->next; r = curr;
        while(curr->next)
        {
            tmp = curr->next;
            prev->next = tmp;
            curr->next = tmp->next;
            prev = tmp;
            curr = tmp->next;
        }
        prev->next = NULL;
        return r;
    }
};