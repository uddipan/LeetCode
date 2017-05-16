class Solution {
public:
    vector<vector<string>> V;
    bool isPalin(string &S)
    {
        if(S.empty())return true;
        int idx1 = 0, idx2 = S.size()-1;
        while(idx1 < idx2)
        {
            if(S[idx1] != S[idx2])
            {
                return false;
            }
            idx1++;idx2--;
        }
        return true;
    }
    
    void part(string S, vector<string>curr)
    {
        if(S.empty())
        {
            V.push_back(curr);
            return;
        }
        
        for(int i=0; i<S.size(); i++)
        {
            string T = S.substr(0, i+1);
            if(isPalin(T))
            {
                vector<string>tmp(curr);
                tmp.push_back(T);
                part(S.substr(i+1),tmp);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        V = vector<vector<string>>();
        if(s.empty())return V;
        part(s,vector<string>());
        return V;
    }
};