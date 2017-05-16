class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int sum = 0, carry = 0;
        int i = a.size()-1, j = b.size()-1;
        while(i>=0 || j >=0)
        {
            if(i>=0 && j>=0)
            {
                sum = int(a[i] - '0') + int(b[j] - '0') + carry;
                i--;j--;
            }
            else if (i >= 0)
            {
                sum = int(a[i] - '0') + carry;
                i--;
            }
            else
            {
                sum = int(b[j] - '0') + carry;
                j--;
            }
            carry = sum/2;
            sum = sum%2;
            ret.insert(ret.begin(),char(sum + '0'));
        }
        if(carry == 1)ret.insert(ret.begin(),'1');
        return ret;
    }
};