class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<pair<string,int>> Q;
        Q.push({beginWord,1});
        
        while(!Q.empty())
        {
            auto fr = Q.front();
            Q.pop();
            string curr = fr.first;
            for(unsigned u=0; u<curr.size(); u++)
            {
                char c = curr[u];
                for(char x = 'a' ; x <='z'; x++)
                {
                    if(x != c)
                    {
                        string tmp = curr;
                        tmp[u] = x;
                        if(tmp == endWord)return fr.second+1;
                        if(wordList.find(tmp)!=wordList.end())
                        {
                            wordList.erase(tmp);
                            Q.push({tmp,fr.second+1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};