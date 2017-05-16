class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == " ")return 0;
        while(s[s.length()-1] == ' ')s.pop_back();
        size_t pos = s.find(" ");
        while(pos != -1)
        {
            s=s.substr(pos+1);
            pos = s.find(" ");
        }
        return int(s.length());
    }
};