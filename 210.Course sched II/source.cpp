class Solution {
public:
    vector<int>res;
    vector<int>visited;
    vector<vector<int>>edges;
    
    bool dfs(int idx)
    {
        if(visited[idx] == 1)return false;
        if(visited[idx] == 2)return true;
        
        visited[idx] = 1;
        for(int i=0; i<edges[idx].size(); i++)
        {
            if(dfs(edges[idx][i]) == false)return false;
        }
        visited[idx]=2;
        res.push_back(idx);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        edges = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<int>(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++)
        {
            edges[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        for(int i=0; i<numCourses; i++)
        {
            if(dfs(i) == false)return vector<int>();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};