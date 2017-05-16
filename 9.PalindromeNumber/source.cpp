class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int digits = floor(log10(x)) + 1;
        int mask = pow(10, digits - 1);
        for(int i=0; i<(digits/2); i++)
        {
            if(x/mask != x%10) return false;
            x %= mask;
            x /=10;
            mask /=100;
        }
        return true;
    }
};