class Solution {
public:
    void setBits(string s, int &x)
    {
        for(int i=0; i<s.size(); i++)
        {
            int tmp = int(s[i] - 'a');
            x = x | (1 << tmp);
        }
    }
    int maxProduct(vector<string>& words) {
        if(words.empty())return 0;
        vector<int>M(words.size(),0);
        for(int i=0; i<words.size(); i++)
        {
            setBits(words[i], M[i]);
        }
        
        int maxP = 0;
        for(int i=0; i<words.size()-1; i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                if((M[i] & M[j]) == 0)
                {
                    int prod = words[i].size()*words[j].size();
                    maxP = max(maxP, prod);
                }
            }
        }
        return maxP;
    }
};