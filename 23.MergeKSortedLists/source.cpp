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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 1)return lists[0];
        if(lists.empty())return NULL;
        multimap<int,int> pq;
        for(auto i=0; i<lists.size(); i++)
        {
            if(lists[i])
            {
                pq.insert(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        ListNode *ret = new ListNode(-1);
        ListNode *head = ret;
        while(!pq.empty())
        {
            pair<int,int>P = *(pq.begin());
            ret->next = new ListNode(P.first);
            ret = ret->next;
            pq.erase(pq.begin());
            int listId = P.second;
            if(lists[listId])
            {
                pq.insert(make_pair(lists[listId]->val, listId));
                lists[listId] = lists[listId]->next;
            }
        }
        return head->next;
    }
};