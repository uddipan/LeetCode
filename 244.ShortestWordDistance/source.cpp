class WordDistance {
public:
    map<string, vector<int>>M;
    WordDistance(vector<string>& words) {
        for(auto i=0; i<words.size(); i++)
        {
            if(M.find(words[i]) == M.end())
            {
                M[words[i]] = vector<int>(1,i);
            }
            else
            {
                M[words[i]].push_back(i);
            }
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>A = M[word1], B= M[word2];
        int dist = INT_MAX;
        for(auto i=0; i<A.size(); i++)
        {
            for(auto j=0; j<B.size(); j++)
            {
                dist = min(dist, abs(A[i]-B[j]));
            }
        }
        return dist;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");