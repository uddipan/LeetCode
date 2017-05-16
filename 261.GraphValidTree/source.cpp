class Solution {
public:
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n < 2)return true;
        vector<int>tmp;
        vector<vector<int>>adj(n,tmp);
        
        //form the adj list
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        
        queue<int>Q;
        Q.push(0);
        vector<bool>v2(n,false);
        vector<int>parent(n,0);
        
        while(!Q.empty())
        {
            int fr = Q.front();
            Q.pop();
            v2[fr] = true;
            for(auto i=0; i<adj[fr].size(); i++)
            {
                if(parent[fr] == adj[fr][i])continue;
                parent[adj[fr][i]] = fr;
                if(v2[adj[fr][i]])return false;
                Q.push(adj[fr][i]);
            }
        }
        for(auto it=v2.begin(); it != v2.end(); ++it)
        {
            if(*it == false)return false;
        }
        return true;
    }
    
};