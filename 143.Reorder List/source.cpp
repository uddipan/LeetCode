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
    ListNode* reverse(ListNode* head)
    {
        ListNode* n = head, *prev = NULL;
        ListNode* tmp;
        while(n)
        {
            tmp = n->next;
            n->next = prev;
            prev = n;
            n = tmp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        fast = head;
        ListNode* dummy = new ListNode(0);
        ListNode *tmp = dummy;
        bool toggle = true;
        while(fast && slow)
        {
            if(toggle)
            {
                dummy->next = fast;
                fast = fast->next;
            }
            else
            {
                dummy->next = slow;
                slow = slow->next;
            }
            toggle = !toggle;
            dummy = dummy->next;
        }
        
        head =  tmp->next;
    }
};