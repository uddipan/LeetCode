class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        bool visited[26] = {false};
        for(int i=0; i<s.size(); i++)
        {
            count[int(s[i]-'a')]++;
        }
        stack<char>S;
        for(int i=0; i<s.size(); i++)
        {
            count[s[i] - 'a']--;
            if(visited[s[i] - 'a'])continue;
            while(!S.empty() && S.top() > s[i] && count[S.top() - 'a'] > 0)
            {
                visited[S.top() - 'a'] = false;
                S.pop();
            }
            S.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string ret;
        while(!S.empty())
        {
            ret.insert(ret.begin(),S.top());
            S.pop();
        }
        return ret;
    }
};