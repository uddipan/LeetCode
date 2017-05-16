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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* result = new ListNode(-1);
        ListNode* tmp = result;
        while(l1 || l2 || carry)
        {
            int a = 0, b = 0;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            sum = a + b + carry;
            result->next = new ListNode(sum%10);
            result = result->next;
            carry = sum/10;
        }
        
        return (tmp->next);
    }
};