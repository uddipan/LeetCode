class Solution {
public:
    vector<vector<int>>cache;
    int helper(string word1, string word2)
    {
        if(cache[word1.size()-1][word2.size()-1] != -1)
        {
            return cache[word1.size()-1][word2.size()-1];
        }
        int a = 1 + helper(word1,word2.substr(0,word2.size()-1));
        int b = 1 + helper(word1.substr(0,word1.size()-1),word2);
        int c = (word1[word1.size()-1] == word2[word2.size()-1]) +
        helper(word1.substr(0,word1.size()-1),word2.substr(0,word2.size()-1));
        cache[word1.size()-1][word2.size()-1] = min(a,min(b,c));
        return cache[word1.size()-1][word2.size()-1];
    }
    
    int minDistance(string word1, string word2) {
        if(word1.empty())return word2.size();
        if(word2.empty())return word1.size();
        
        cache = vector<vector<int>>(word1.size(), vector<int>(word2.size(),-1));
        for(int i=0; i<word1.size(); i++)
        {
            cache[i][0] = i;
        }
        for(int i=0; i<word2.size(); i++)
        {
            cache[0][i] = i;
        }
        return helper(word1,word2);
    }
};