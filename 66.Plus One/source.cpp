class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())return vector<int>();
        vector<int>V;
        int sum = 0, carry = 0;
        int x = 1;
        for(int i=digits.size()-1; i>=0; i--)
        {
            sum = carry + x + digits[i];
            V.insert(V.begin(),sum%10);
            carry = sum/10;
            x = 0;
        }
        if(carry)
        {
            V.insert(V.begin(),carry%10);
        }
        return V;
    }
};