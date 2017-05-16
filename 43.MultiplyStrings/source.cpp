class Solution {
public:
    string Add(string &num1, string &num2)
    {
        int carry = 0, sum = 0;
        int i = int(num1.size()) - 1, j = int(num2.size()) - 1;
        string S;
        while((i >= 0) || (j >= 0))
        {
            int a = 0, b = 0;
            if(i >= 0)a = int(num1[i] - '0');
            if(j >= 0)b = int(num2[j] - '0');
            sum = carry + a + b;
            carry = sum/10;
            sum %= 10;
            S.insert(S.begin(),char(sum) + '0');
            i--;
            j--;
        }
        if(carry)S.insert(S.begin(),char(carry) + '0');
        return S;
    }
    
    string Prod(string &num1, char &c)
    {
        int x = int(c - '0');
        int i = int(num1.size()) - 1;
        int sum = 0, carry = 0;
        string S;
        while(i >= 0)
        {
            int y = int(num1[i] - '0');
            sum = x*y + carry;
            carry = sum/10;
            sum %= 10;
            S.insert(S.begin(),char(sum) + '0');
            i--;
        }
        if(carry)S.insert(S.begin(),char(carry) + '0');
        return S;
    }
    
    
    string multiply(string num1, string num2) {
        string S, append = "";
        char t;
        // if(num1.size() < num2.size())
        {
            for(int i = int(num1.size()) - 1; i>=0; i--)
            {
                t = num1[i];
                string T = Prod(num2,t);
                T.insert(T.end(), append.begin(), append.end());
                S = Add(S,T);
                append.push_back('0');
            }
        }
        while(S[0] == '0')S.erase(S.begin());
        if(S.empty())return "0";
        return S;
    }
};