class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>M;
        vector<vector<string>> V;
        for(auto i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(M.find(s) != M.end())
            {
                M[s].push_back(strs[i]);
            }
            else
            {
                M[s] = vector<string>(1,strs[i]);
            }
        }
        
        for(auto it = M.begin(); it != M.end(); ++it)
        {
            vector<string>w = (*it).second;
            sort(w.begin(),w.end());
            V.push_back(w);
        }
        return V;
    }
};