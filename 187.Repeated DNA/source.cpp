class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>V;
        if(s.size() < 10)
        {
            return V;
        }
        
        map<string,int>M;
        for(int i=0; i<=s.size() - 10; i++)
        {
            string t = s.substr(i,10);
            if(M.find(t) == M.end())
            {
                M[t] = 1;
            }
            else
            {
                M[t]++;
            }
        }
        for(auto it = M.begin(); it != M.end(); ++it)
        {
            if(it->second > 1)
            {
                V.push_back(it->first);
            }
        }
        return V;
    }
};