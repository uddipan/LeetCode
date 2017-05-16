class Solution {
public:
    vector<vector<int>> adj;
    vector<bool>visited;
    
    bool noCycle(int startNode)
    {
        queue<int>Q;
        Q.push(startNode);
        while(!Q.empty())
        {
            int fr = Q.front();
            visited[fr] = true;
            Q.pop();
            for(int i=0; i<adj[fr].size(); i++)
            {
                if(visited[adj[fr][i]])return false;
                Q.push(adj[fr][i]);
            }
        }
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.empty() || numCourses == 0)return true;
        visited = vector<bool>(numCourses,false);
        adj = vector<vector<int>>(numCourses,vector<int>());
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        int start = 0;
        while(start < numCourses)
        {
            //if(visited[start] == false)
            {
                if(!noCycle(start))return false;
                visited = vector<bool>(numCourses,false);
            }
            start++;
        }
        return true;
    }
};