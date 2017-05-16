class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>V;
        if(n == 1)
        {
            V.push_back(0);
            return V;
        }
        
        vector<vector<int>>adj(n, vector<int>());
        vector<int>degrees(n,0);
        for(int i=0; i<edges.size(); i++)
        {
            auto p = edges[i];
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
            degrees[p.first] = adj[p.first].size();
            degrees[p.second] = adj[p.second].size();
        }
        
        int cnt = n;
        while(cnt > 2)
        {
            vector<int>affected;
            for(int i=0; i<degrees.size(); i++)
            {
                if(degrees[i] == 1)
                {
                    degrees[i] = -1;
                    cnt--;
                    affected.push_back(i);
                }
            }
            for(int i=0; i<affected.size(); i++)
            {
                for(int j=0; j<adj[affected[i]].size(); j++)
                {
                    degrees[adj[affected[i]][j]]--;
                }
            }
        }
        for(int i=0; i<degrees.size(); i++)
        {
            if(degrees[i] == 0 || degrees[i] == 1)
            {
                V.push_back(i);
            }
        }
        return V;
    }
};