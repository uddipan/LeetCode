class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n)
        {
            int x = (n%26 + 25)%26;
            s.insert(s.begin(),(x + 'A'));
            n = (n-1)/26;
        }
        return s;
    }
};