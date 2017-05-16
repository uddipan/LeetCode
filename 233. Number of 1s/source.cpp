class Solution {
public:
    //https://leetcode.com/discuss/95504/easy-to-understand-0ms-solution-with-detailed-explanation#
    int func(int n)
    {
        if(n <= 0) return 0;
        if(n <= 9) return 1;
        
        unordered_map<int, int> M;
        M[9] = 1;
        for(int i = 9; i <= (INT_MAX - 9) / 10; i = i * 10 + 9){
            M[i*10 + 9] = M[i] * 10 + (i + 1); // mp[99], mp[999], mp[9999], ... ...
        }
        
        int nn = n, div = 1;
        while(nn / 10){
            nn /= 10;
            div *= 10;
        }
        int x = n / div;
        int y = n % div;//356
        int ans = 0;
        ans += x *  M[div - 1];
        ans += (x > 1) ? div : 0;
        ans += (x == 1) ? n % div + 1 : 0;
        ans += func(y);
        return ans;
    }
    int countDigitOne(int n) {
        if(n <= 0)return 0;
        return func(n);
    }
};
