/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)return node;
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        queue<pair<UndirectedGraphNode*, UndirectedGraphNode*>>Q;
        Q.push({node,newNode});
        while(!Q.empty())
        {
            auto fr = Q.front();
            Q.pop();
            for(unsigned u=0; u<fr.first->neighbors.size(); u++)
            {
                UndirectedGraphNode* member = fr.first->neighbors[u];
                UndirectedGraphNode* newMember = new UndirectedGraphNode(member->label);
                fr.second->neighbors.push_back(newMember);
                Q.push({member,newMember});
            }
        }
        return newNode;
    }
};