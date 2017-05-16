class Solution {
public:
    void rev(string &S, int pos1, int pos2)
    {
        if(S.empty())return;
        while(pos1 < pos2)
        {
            char c = S[pos1];
            S[pos1] = S[pos2];
            S[pos2] = c;
            pos1++;
            pos2--;
        }
    }
    void reverseWords(string &s) {
        if(s.empty())return ;
        while(s[0] == ' ')s.erase(s.begin());
        while(!s.empty() && s[s.size()-1] == ' ')s.pop_back();
        //if(s[0] == ' '){s = string(); return;}
        int id = 1;
        while(id < s.size())
        {
            if(s[id] == ' ' && s[id-1] == ' ')
            {
                s.erase(s.begin()+id);
            }
            else id++;
        }
        int idx1 = 0, idx2 = 0;
        while(idx2 < s.size())
        {
            if(s[idx2] == ' ')
            {
                rev(s, idx1, idx2-1);
                idx2++;
                idx1 = idx2;
            }
            else
            {
                idx2++;
            }
        }
        
        rev(s, idx1, idx2-1);
        rev(s,0, s.size()-1);
    }
};