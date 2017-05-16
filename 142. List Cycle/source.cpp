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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)return NULL;
        ListNode* fast=head, *slow = head;
        if(fast->next == NULL)return NULL;
        fast = fast->next->next;
        slow = slow->next;
        while(slow != fast && fast !=NULL && slow != NULL)
        {
            if(fast->next == NULL)return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == NULL || slow == NULL)return NULL;
        
        int len = 1;
        slow = slow->next;
        while(slow!=fast)
        {
            slow = slow->next;
            len++;
        }
        slow = head; fast = head;
        while(len--)fast = fast->next;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};