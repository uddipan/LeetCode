class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if(n < 2)return n;
        set<int> inQueue;
        for(auto i=0; i<n; i++)inQueue.insert(i);
        
        queue<int>Q;
        Q.push(0);
        int conn = 0;
        
        map<int, vector<int>>adj;
        for(auto i=0; i<edges.size(); i++)
        {
            if(adj.find(edges[i].first) != adj.end())
            {
                adj[edges[i].first].push_back(edges[i].second);
            }
            else
            {
                adj[edges[i].first] = vector<int>(1,edges[i].second);
            }
            if(adj.find(edges[i].second) != adj.end())
            {
                adj[edges[i].second].push_back(edges[i].first);
            }
            else
            {
                adj[edges[i].second] = vector<int>(1,edges[i].first);
            }
        }
        vector<bool>visited(n,false);
        visited[0] = true;
        
        while(!Q.empty() || !inQueue.empty())
        {
            if(!Q.empty())
            {
                int fr = Q.front();
                Q.pop();
                auto x = inQueue.find(fr);
                inQueue.erase(x);
                if(adj.find(fr) != adj.end())
                {
                    for(auto i=0; i<adj[fr].size(); i++)
                    {
                        if(!visited[adj[fr][i]])
                        {
                            Q.push(adj[fr][i]);
                            visited[adj[fr][i]] = true;
                        }
                    }
                }
                if(Q.empty())conn++;
            }
            else
            {
                Q.push(*inQueue.begin());
                visited[*inQueue.begin()] = true;
            }
        }
        return conn;
    }
    
    
};