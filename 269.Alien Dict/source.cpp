class Solution {
public:
    void topSort(string &alphabets, map<char,string> &adj, stack<char>&S, map<char,bool>&visited, char c)
    {
        visited[c] = true;
        for(unsigned u = 0; u<adj[c].size(); u++)
        {
            char ct = adj[c][u];
            if(!visited[ct])
            {
                topSort(alphabets, adj, S, visited, ct);
            }
            
        }
        S.push(c);
    }
    
    string alienOrder(vector<string>& words) {
        string ret;
        if(words.empty())return ret;
        string alphabets;
        map<char,string>adj;
        stack<char>S;
        map<char,bool>visited;
        for(int i=0; i<words.size()-1; i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                int idx1 = 0, idx2 = 0;
                while(idx1 < words[i].size() && idx2 < words[j].size() && words[i][idx1] == words[j][idx2])
                {
                    idx1++;
                    idx2++;
                }
                if(idx1 < words[i].size() && idx2 < words[j].size())
                {
                    if(adj.find(words[i][idx1]) == adj.end())
                    {
                        adj[words[i][idx1]] = string(1,words[j][idx2]);
                    }
                    else
                    {
                        adj[words[i][idx1]].push_back(words[j][idx2]);
                    }
                    if(adj.find(words[j][idx2]) != adj.end())
                    {
                        string tmp = adj[words[j][idx2]];
                        if(tmp.find(words[i][idx1]) != string::npos)return "";
                    }
                }
            }
        }
        
        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                if(visited.find(words[i][j]) == visited.end())
                {
                    visited[words[i][j]] = false;
                    alphabets.push_back(words[i][j]);
                }
            }
        }
        
        
        for(auto it = visited.begin(); it !=visited.end(); ++it)
        {
            if(!it->second)
            {
                topSort(alphabets, adj, S, visited, it->first);
            }
        }
        
        
        while(!S.empty())
        {
            ret.push_back(S.top());
            S.pop();
        }
        return ret;
    }
};