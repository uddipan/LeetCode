class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>V;
        if(words.empty())return V;
        map<string,int>M;
        for(int i=0; i<words.size(); i++)
        {
            M[words[i]] = i;
        }
        for(int i=0; i<words.size(); i++)
        {
            string s1 = words[i];
            reverse(s1.begin(), s1.end());
            string s2 = s1;
            s2.erase(s2.begin());
            if(M.find(s1) != M.end())
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(M[s1]);
                V.push_back(tmp);
            }
            if(M.find(s2) != M.end())
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(M[s2]);
                V.push_back(tmp);
            }
        }
        return V;
    }
};