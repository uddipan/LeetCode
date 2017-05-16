/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* N;
    TreeNode* helper(int start, int end)
    {
        if(start > end) return NULL;
        int mid = start + (end - start)/2;
        TreeNode *left = helper(start, mid-1);
        TreeNode *p = new TreeNode(N->val);
        N = N->next;
        TreeNode *right = helper(mid+1,end);
        p->left = left;
        p->right = right;
        return p;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        N = head;
        int len = 0;
        while(p)
        {
            p = p->next;
            len++;
        }
        return helper(0, len-1);
    }
};