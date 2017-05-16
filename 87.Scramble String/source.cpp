class Solution {
public:
    bool scram(string s1, string s2)
    {
        if(s1.size() != s2.size())return false;
        if(s1 == s2)return true;
        if(!is_permutation(s1.begin(),s1.end(),s2.begin()))return false;
        for(int i=1 ; i<s1.size(); i++)
        {
            if((scram(s1.substr(0,i),s2.substr(0,i)) && scram(s1.substr(i),s2.substr(i))) ||
               (scram(s1.substr(0,i),s2.substr(s2.size()-i)) && scram(s1.substr(i),s2.substr(0,s2.size()-i))))
                return true;
        }
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        return scram(s1,s2);
    }
};